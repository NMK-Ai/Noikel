#!/usr/bin/env python3
import os
import importlib
from openpilot.common.basedir import BASEDIR
from openpilot.common.params import Params
import json

def is_car_model(car_class, attr):
  # Check if the attribute is not callable and is not a dunder attribute
  return not callable(getattr(car_class, attr)) and not attr.startswith("__")

def move_to_proper_group(models, prefix, target_group):
  """
  Moves models with a certain prefix to their respective group.
  Example: Models starting with 'LEXUS_' should go to 'Lexus' group.
  """
  moved_models = []
  for model in models[:]:  # Iterate over a copy of the list to avoid modifying the list during iteration
    if model.startswith(prefix):
      moved_models.append(model)
      models.remove(model)  # Remove from the original group
  return moved_models

def format_group_name(group_name, exceptions):
  """
  Formats group names according to the exceptions dictionary.
  Groups in the exceptions dictionary are returned in all caps, others are title cased.
  """
  return exceptions.get(group_name, group_name.title())

base_package = "opendbc.car"
base_path = f"{BASEDIR}/opendbc/car"

# List all subdirectories (car brands)
car_brands = sorted([
  name for name in os.listdir(base_path)
  if os.path.isdir(os.path.join(base_path, name)) and not name.startswith("__")
])

grouped_models = {}

# Define the lookup dictionary for brand-to-group mappings
brand_to_group_map = {
  "chrysler": [
    {
      "prefix": "DODGE_",
      "group": "Dodge"
    },
    {
      "prefix": "RAM_",
      "group": "Ram"
    },
    {
      "prefix": "JEEP_",
      "group": "Jeep"
    },
  ],
  "gm": [
    {
      "prefix": "BUICK_",
      "group": "Buick"
    },
    {
      "prefix": "CADILLAC_",
      "group": "Cadillac"
    },
    {
      "prefix": "CHEVROLET_",
      "group": "Chevrolet"
    },
    {
      "prefix": "HOLDEN_",
      "group": "Holden"
    },
  ],
  "honda": {
    "prefix": "ACURA_",
    "group": "Acura"
  },
  "toyota": {
    "prefix": "LEXUS_",
    "group": "Lexus"
  },
  "hyundai": [
    {
      "prefix": "KIA_",
      "group": "Kia"
    },
    {
      "prefix": "GENESIS_",
      "group": "Genesis"
    }
  ],
  "volkswagen": [
    {
      "prefix": "AUDI_",
      "group": "Audi"
    },
    {
      "prefix": "SKODA_",
      "group": "Skoda"
    },
    {
      "prefix": "SEAT_",
      "group": "Seat"
    }
  ]
}

# Define exceptions for group names
group_name_exceptions = {
  "gm": "GM",
}

exclude_brands = ['body', 'mock']

# Import CAR from each subdirectory and group models by brand
for brand in car_brands:
  if brand in exclude_brands:
    continue
  module_name = f"{base_package}.{brand}.values"
  try:
    module = importlib.import_module(module_name)
    if hasattr(module, "CAR"):
      car_class = getattr(module, "CAR")
      models = sorted([attr for attr in dir(car_class) if is_car_model(car_class, attr)])

      # Check if the brand has a special group in the lookup map
      if brand in brand_to_group_map:
        group_info = brand_to_group_map[brand]

        if isinstance(group_info, list):  # If multiple prefixes for the brand
          for prefix_info in group_info:
            moved_models = move_to_proper_group(models, prefix_info["prefix"], prefix_info["group"])
            if moved_models:
              if prefix_info["group"] not in grouped_models:
                grouped_models[prefix_info["group"]] = []
              grouped_models[prefix_info["group"]].extend(moved_models)
        else:  # Single prefix for the brand
          moved_models = move_to_proper_group(models, group_info["prefix"], group_info["group"])
          if moved_models:
            if group_info["group"] not in grouped_models:
              grouped_models[group_info["group"]] = []
            grouped_models[group_info["group"]].extend(moved_models)

      # Add remaining models to the respective brand
      if models:
        grouped_models[brand] = models
  except ModuleNotFoundError:
    pass

# Sort the groups alphabetically
sorted_grouped_models = sorted(grouped_models.items(), key=lambda x: x[0])

# Convert to the desired output structure, ensuring models are sorted within each group
output = [{"group": format_group_name(group, group_name_exceptions), "models": sorted(models)} for group, models in sorted_grouped_models]

# Store the JSON output in Params
Params().put("null_general_model_list", json.dumps(output))

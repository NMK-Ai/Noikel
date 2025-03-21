from opendbc.car.toyota.values import ToyotaFlags
from opendbc.can.parser import CANParser

ANGLE_DIFF_THRESHOLD = 4.0
THRESHOLD_COUNT = 10

class ZSS:

  def __init__(self, flags: int):
    self._enabled = flags & ToyotaFlags.ZSS.value
    self._alka_enabled = flags & ToyotaFlags.ALKA.value

    self._offset_compute_required = False
    self._lka_active_prev = False
    self._angle_offset = 0.
    self._threshold_count = 0
    self._zss_value = 0.

  def set_values(self, cp: CANParser):
    self._zss_value = cp.vl["SECONDARY_STEER_ANGLE"]["ZORRO_STEER"]

  def get_enabled(self):
    return self._enabled

  def get_steering_angle_deg(self, main_on, cruise_active, steering_angle_deg):
    # off, fall back to stock
    if not self._enabled:
      return steering_angle_deg

    # too many failure, fallback to stock
    if self._threshold_count > THRESHOLD_COUNT:
      print("ZSS: Too many failure, fallback to stock.")
      return steering_angle_deg

    self._compute_offset(main_on, cruise_active, steering_angle_deg)

    new_steering_angle_deg = self._zss_value - self._angle_offset

    # error check, when difference between stock vs new angle deg is too large
    if abs(steering_angle_deg - new_steering_angle_deg) > ANGLE_DIFF_THRESHOLD:
      self._threshold_count += 1

    # send back zss angle deg
    return new_steering_angle_deg

  def _compute_offset(self, main_on, cruise_active, steering_angle_deg):
    # When alka is on, check main_on state
    # cp_vl["PCM_CRUISE_2"]["MAIN_ON"] / cp_vl["PCM_CRUISE"]["CRUISE_ACTIVE"])
    lka_active = (self._alka_enabled and main_on != 0) or bool(cruise_active)

    # only compute zss offset when lka is active
    if lka_active and not self._lka_active_prev:
      self._threshold_count = 0
      self._offset_compute_required = True # cruise was just activated, so allow offset to be recomputed
    self._lka_active_prev = lka_active

    # compute zss offset once
    if self._offset_compute_required:
      if abs(steering_angle_deg) > 1e-3 and abs(self._zss_value) > 1e-3:
        self._offset_compute_required = False
        self._angle_offset = self._zss_value - steering_angle_deg

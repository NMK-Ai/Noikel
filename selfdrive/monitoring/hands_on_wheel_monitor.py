from cereal import custom, car
from common.conversions import Conversions as CV

EventName = car.CarEvent.EventName
HandsOnWheelState = custom.DriverMonitoringStateSP.HandsOnWheelState

_PRE_ALERT_THRESHOLD = 150  # 15s
_PROMPT_ALERT_THRESHOLD = 300  # 30s
_TERMINAL_ALERT_THRESHOLD = 800  # 80s

_MIN_MONITORING_SPEED = 10 * CV.KPH_TO_MS  # No monitoring under 10kph


class HandsOnWheelStatus():
  def __init__(self):
    self.hands_on_wheel_state = HandsOnWheelState.none
    self.hands_off_wheel_cnt = 0

  def update(self, events, steering_wheel_engaged, ctrl_active, v_ego, always_on, hands_on_wheel_monitoring):
    if v_ego < _MIN_MONITORING_SPEED or \
       (not always_on and not ctrl_active) or \
       (always_on and not ctrl_active and self.hands_on_wheel_state == HandsOnWheelState.terminal) or \
       not hands_on_wheel_monitoring:
      self.hands_on_wheel_state = HandsOnWheelState.none
      self.hands_off_wheel_cnt = 0
      return

    if steering_wheel_engaged:
      # Driver has hands on steering wheel
      self.hands_on_wheel_state = HandsOnWheelState.ok
      self.hands_off_wheel_cnt = 0
      return

    self.hands_off_wheel_cnt += 1
    alert = None

    if self.hands_off_wheel_cnt >= _TERMINAL_ALERT_THRESHOLD:
      # terminal red alert: disengagement required
      self.hands_on_wheel_state = HandsOnWheelState.terminal
      alert = EventName.keepHandsOnWheel
    elif self.hands_off_wheel_cnt >= _PROMPT_ALERT_THRESHOLD:
      # prompt orange alert
      self.hands_on_wheel_state = HandsOnWheelState.critical
      alert = EventName.promptKeepHandsOnWheel
    elif self.hands_off_wheel_cnt >= _PRE_ALERT_THRESHOLD:
      # pre green alert
      self.hands_on_wheel_state = HandsOnWheelState.warning
      alert = EventName.preKeepHandsOnWheel
    else:
      # hands off wheel for acceptable period of time.
      self.hands_on_wheel_state = HandsOnWheelState.minor

    if alert is not None:
      events.add(alert)

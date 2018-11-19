void comm_receive() {



  mavlink_message_t msg;
  mavlink_status_t status;

  while (Serial1.available() > 0 )
  {
    uint8_t c = Serial1.read();
    if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
      handle_message(&msg, &status);
    }
  }
}

void handle_message(mavlink_message_t *msg, mavlink_status_t *status) {
  int cycle = 1;
  switch (msg->msgid)
  {

    case MAVLINK_MSG_ID_GPS_RAW_INT:
      mavlink_gps_raw_int_t gps_raw;
      mavlink_msg_gps_raw_int_decode(msg, &gps_raw);
      Time = mavlink_msg_gps_raw_int_get_time_usec(msg);
      Fix = mavlink_msg_gps_raw_int_get_fix_type(msg);
      Sat = mavlink_msg_gps_raw_int_get_satellites_visible(msg);
      if (Fix > 2) {
        Speed = (mavlink_msg_gps_raw_int_get_vel(msg) / 1000) * 3.6;
        Serial.print(mavlink_msg_gps_raw_int_get_vel(msg) / 100000);
        Serial.print("\t");
        Serial.print(Speed);
        Lat = mavlink_msg_gps_raw_int_get_lat(msg) / 10000000.0f;
        Lon = mavlink_msg_gps_raw_int_get_lon(msg) / 10000000.0f;
      }
      break;

      if (cycle == 1) {
      case MAVLINK_MSG_ID_HEARTBEAT:
        Mode = mavlink_msg_heartbeat_get_custom_mode(msg);
        State = mavlink_msg_heartbeat_get_base_mode(msg);
        break;
      }

      if (cycle == 1) {
      case MAVLINK_MSG_ID_VFR_HUD:
        Alt = mavlink_msg_vfr_hud_get_alt(msg) * 10;
        Course = mavlink_msg_vfr_hud_get_heading(msg);
        break;
      }

      if (cycle == 1) {
      case MAVLINK_MSG_ID_SYS_STATUS:
        Volt = mavlink_msg_sys_status_get_voltage_battery(msg) / 100;
        Current  = mavlink_msg_sys_status_get_current_battery(msg);
        BatP =  mavlink_msg_sys_status_get_battery_remaining(msg);
        break;
      }

      if (cycle == 1) {
      case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
        Rssi = mavlink_msg_rc_channels_raw_get_rssi(msg);
        break;
      }
  }
}


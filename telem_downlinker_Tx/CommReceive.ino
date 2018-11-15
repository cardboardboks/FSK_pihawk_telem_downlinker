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
  switch (msg->msgid)
  {
    case MAVLINK_MSG_ID_VFR_HUD:
      Alt = mavlink_msg_vfr_hud_get_alt(msg);
      Course = mavlink_msg_vfr_hud_get_heading(msg);
      break;

    case MAVLINK_MSG_ID_SYS_STATUS:
      Volt = (float) mavlink_msg_sys_status_get_voltage_battery(msg) / 1000;
      Current  = (float) mavlink_msg_sys_status_get_current_battery(msg) / 1000;
      BatP = (float) mavlink_msg_sys_status_get_battery_remaining(msg);
      break;

    case MAVLINK_MSG_ID_HEARTBEAT:
      break;

    case MAVLINK_MSG_ID_GPS_RAW_INT:
      mavlink_gps_raw_int_t gps_raw;
      mavlink_msg_gps_raw_int_decode(msg, &gps_raw);
      Speed  =  mavlink_msg_gps_raw_int_get_vel(msg);
      Sat = gps_raw.satellites_visible;
      Lat = mavlink_msg_gps_raw_int_get_lat(msg) / 10000000.0f;
      Lon = mavlink_msg_gps_raw_int_get_lon(msg) / 10000000.0f;
      break;

    case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
      Rssi = mavlink_msg_rc_channels_raw_get_rssi(msg);
      break;
  }
}


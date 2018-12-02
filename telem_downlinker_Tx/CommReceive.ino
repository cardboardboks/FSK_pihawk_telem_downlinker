void CommReceive() {

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

    case MAVLINK_MSG_ID_GPS_RAW_INT:
      bits |= 8;  //Sat
      mavlink_gps_raw_int_t gps_raw;
      mavlink_msg_gps_raw_int_decode(msg, &gps_raw);
      Time = mavlink_msg_gps_raw_int_get_time_usec(msg);
      Fix = mavlink_msg_gps_raw_int_get_fix_type(msg);
      Sat = mavlink_msg_gps_raw_int_get_satellites_visible(msg);
      // if (Fix > 2) {
      bits |= 1;  //Lat
      bits |= 2;  //Lon
      bits |= 4;  //Speed
      Speed = (mavlink_msg_gps_raw_int_get_vel(msg) * 3.6) / 10;
      //      Lat = mavlink_msg_gps_raw_int_get_lat(msg)/10000;
      //      Lon = mavlink_msg_gps_raw_int_get_lon(msg)/10000;
      Lat = -38.45324;
      Lon = 117.56823;
      //}
      //      Serial.println(millis() - milold1);
      //      milold1 = millis();
      break;

    case MAVLINK_MSG_ID_HEARTBEAT:
      bits |= 16;  //Mode
      bits |= 32;  //State
      Mode = mavlink_msg_heartbeat_get_custom_mode(msg);
      State = mavlink_msg_heartbeat_get_base_mode(msg);
      //      Serial.println(millis() - milold2);
      //      milold2 = millis();
      break;

    case MAVLINK_MSG_ID_VFR_HUD:
      bits |= 64;  //Alt
      bits |= 128;  //Course
      Alt = mavlink_msg_vfr_hud_get_alt(msg) * 10;
      Course = mavlink_msg_vfr_hud_get_heading(msg);
      //      Serial.println(millis() - milold3);
      //      milold3 = millis();
      break;

    case MAVLINK_MSG_ID_SYS_STATUS:
      bits |= 256;  //Volt
      bits |= 512;  //Current
      bits |= 1024;  //BatP
      Volt = mavlink_msg_sys_status_get_voltage_battery(msg) / 100;
      Current  = mavlink_msg_sys_status_get_current_battery(msg);
      BatP =  mavlink_msg_sys_status_get_battery_remaining(msg);
      //      Serial.println(millis() - milold4);
      //      milold4 = millis();
      break;

    case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
      bits |= 2048;  //Rssi
      Rssi = mavlink_msg_rc_channels_raw_get_rssi(msg);
      //      Serial.println(millis() - milold5);
      //      milold5 = millis();
      break;
  }

}


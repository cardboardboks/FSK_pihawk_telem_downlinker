
#include <mavlink.h>        // Mavlink interface

int LATI = 0;
int LONI = 0;
int LATF1 = 0;
int LONF1 = 0;
int LATF2 = 0;
int LONF2 = 0;

float Lat = 174.830000;
float Lon = -41.090000;
float Alt = 0;
int Course = 0;
float Volt = 0;
int Current = 0;
int Rssi = 0;
int Packet = 0;
int Sat = 0;
int Spare = 0;
float CheckSum = 0;

int Roll = 0;
int Mode = 0;

void setup() {

  Serial.begin(115200);
  Serial1.begin(57600);
  delay(5000);
  Serial.println("Opening Radio Dongle");

}

void loop() {
  comm_receive();


  Serial.print("Alt=");
  Serial.print(Alt);
  Serial.print("\t");

  Serial.print("Heading=");
  Serial.print(Course);
  Serial.print("\t");

  Serial.print("Voltage=");
  Serial.print (Volt);
  Serial.print("\t");

  Serial.print("Roll=");
  Serial.print (Roll);
  Serial.print("\t");

  Serial.print("Mode=");
  if (Mode == 0) {
    Serial.print("Manual");
  }
  if (Mode == 1) {
    Serial.print("Circle");
  }
  if (Mode == 2) {
    Serial.print("Stabilize");
  }
  if (Mode == 3) {
    Serial.print("Training");
  }
  if (Mode == 4) {
    Serial.print("Acro");
  }
  if (Mode == 5) {
    Serial.print("FBWA");
  }
  if (Mode == 6) {
    Serial.print("FBWB");
  }
  if (Mode == 7) {
    Serial.print("Cruise");
  }
  if (Mode == 8) {
    Serial.print("Autotune");
  }
  if (Mode == 10) {
    Serial.print("Auto");
  }
  if (Mode == 11) {
    Serial.print("RTL");
  }
  if (Mode == 12) {
    Serial.print("Loiter");
  }
  if (Mode == 14) {
    Serial.print("Avoid ADSB");
  }
  if (Mode == 15) {
    Serial.print("Guided");
  }
  if (Mode == 16) {
    Serial.print("Initialising");
  }
  Serial.print("\t");

  Serial.print("Lat=");
  Serial.print (Lat, 6);
  Serial.print("\t");

  Serial.print("Lon=");
  Serial.print (Lon, 6);
  Serial.print("\t");

  Serial.print("Sat Count=");
  Serial.println(Sat);

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
      break;

    case MAVLINK_MSG_ID_ATTITUDE:
      Roll = (mavlink_msg_attitude_get_roll(msg)) * 57296 / 1000;
      break;

    case MAVLINK_MSG_ID_HEARTBEAT:
      //mavlink_heartbeat_t hb;
      //mavlink_msg_heartbeat_decode(msg, &hb);
      Mode = mavlink_msg_heartbeat_get_custom_mode(msg);
      break;

    case MAVLINK_MSG_ID_GPS_RAW_INT:
      mavlink_gps_raw_int_t gps_raw;
      mavlink_msg_gps_raw_int_decode(msg, &gps_raw);
      Sat = gps_raw.satellites_visible;
      Lat = mavlink_msg_gps_raw_int_get_lat(msg) / 10000000.0f;
      Lon = mavlink_msg_gps_raw_int_get_lon(msg) / 10000000.0f;
      //osd_fix_type = mavlink_msg_gps_raw_int_get_fix_type(&msg);
      //osd_satellites_visible = mavlink_msg_gps_raw_int_get_satellites_visible(&msg);
      break;


  }
}

void comm_receive() {

  mavlink_message_t msg;
  mavlink_status_t status;

  while (Serial1.available() > 0 )
  {
    uint8_t c = Serial1.read();
    if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
      handle_message(&msg, &status);
    }
    // And get the next one
  }

}





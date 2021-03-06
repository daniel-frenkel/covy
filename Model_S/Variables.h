#define DIR_OPEN 1
#define DIR_CLOSE 2
#define HOLD_OPEN 3
#define HOLD_CLOSE 4
#define MOVE_OPEN 5
#define STOP 6
#define MOVE_CLOSE 7
#define AUTO_CALIBRATE 8
#define SET_MAX_STEPS 9
#define CUSTOM_MOVE 10
#define POSITION_CLOSE 11
#define POSITION_ADJUST 12
//#define FULL_CLOSE 13
#define STEP_1 14
#define STEP_2 15
#define STEP_3 16
#define STEP_4 17
#define STEP_5 18
#define STEP_6 19
#define FORCE_CLOSE 20


int stall_close;
int stall_open;
int current_close;
int current_open;
float move_percent;
float move_distance;
int velocity;
bool move_close_stall;
bool move_open_stall;

int waitTime;
int lowTime;
int maxCloseTime;

int MOVE_OPEN_VELOCITY = 120000;
int MOVE_CLOSE_VELOCITY = 120000;
int MOVE_ACCEL = 300;
int MOVE_DECEL = 800;
int MOVE_DECEL_CLOSED = 800;
int setup_current = 3072;

//Step 3 Current
int open_current_setup_value = 4;
int close_current_setup_value = 4;
int open_stall_current_setup = 25;
int close_stall_current_setup = 25;

//Step 4

int current_open_passes = 4;
int current_low_open_passes = 4;

int step_4_open_stall_high = -5;
int step_4_close_stall_high = -5;

int step_5_open_stall_low = -5;
int step_5_close_stall_low = -5;

int step_4_open_passes = 10;
int step_4_close_passes = 10;

float gear_ratio = 1;
float inches_mm = 25.4;
int microsteps = 256; //For some reason 64 works/ Should be 256
int full_steps_mm = 0.1508;//30.16;

float one_inch = 51200*1.063825331607758; //3.8mm radius

int stall_close_high;
int stall_open_high;
int stall_close_low;
int stall_open_low;

//int close_current;
//int open_current;
int current_setup = 3840;

float move_to_position;
float open_percent;

bool restart_movement;

bool blynk_update = false;

bool Orientation_Right;

unsigned long sendData(unsigned long address, unsigned long datagram);

int XACTUAL;

long check_timer = 0;
long daylight_timer = 0;

long last_timezone_offset=-1;

void save_time(int i);

int command = -1;

int current_position;

int max_steps;
int move_direction;
int CLOSE_POSITION;
float OPEN_CLOSE_position;

int open_stall_calibration;
int open_stall_calibration_value;
int close_stall_calibration;
int close_stall_calibration_value;

int open_current_calibration;
int open_current_calibration_value;

int close_current_calibration;
int close_current_calibration_value;

bool motor_running = false;

bool MQTT_ON = false;
bool MQTT_SETUP = false;
bool reverse_flag = false;

String mqtt_name = "MorningRod";
String mqtt_server = "192.168.50.178";

String mqtt_username = "username";
String mqtt_password = "password";

//HA Auto Discovery
String disc_prefix = "homeassistant";
String mqtt_discovery_topic = "homeassistant/cover/MorningRod/config";
String mqtt_state_topic =  "homeassistant/cover/MorningRod/state";
String mqtt_set_topic =  "homeassistant/cover/MorningRod/set";
String mqtt_discovery_payload;

bool buzzer_flag = false;
int auto_close_time = 0;

void delayStall(long timeout);
void waitStall(long timeout);
void turnMotor(int dir);

bool stall_flag = false;

int moveFreq = 1000;
int move_time_on = 100;
int moveChannel = 13;
int moveResolution = 16;

int number_open_passes;
int number_close_passes;
int calibration_direction;

// State variables will change:
int windowState = 0;         // current state of the door
int lastWindowState = 0;     // previous state of the door
int stallOpenState = 0;
int lastStallOpenState = 0;
int stallCloseState = 0;
int lastStallCloseState = 0;

int buzzerId;
int dogBuzzerId;
int schedulerId;
int notifyId;
bool door_status_opened;

int just_open_position; 
bool just_open_set_button = false;
int stepValue;
bool fast_loud;

int dogInterval = 5000;

// State variables will change:
int doorState = LOW;         // current state of the door
int lastdoorState = LOW;     // previous state of the door

int run_section;
float slider_display;
float slider_XACTUAL;
bool stall_buzzer_blynk;
int timer_open_percent;
using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FR;
extern motor BR;
extern motor FL;
extern motor BL;
extern inertial Inertial_sensor;
extern motor example_motor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
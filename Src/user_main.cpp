#include <AP_Motors.h>
#include <AC_PID.h>

AC_PID    *pid_1, *pid_2, *pid_3, *pid_4;
AP_Motors *motor1_fr, *motor2_fl, *motor3_bl, *motor4_br;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim8;

#if (defined(__GNUC__) || defined(__CC_ARM)) && defined(__cplusplus)
extern "C" {
#endif
void setup(void)
{
  pid_1     = new AC_PID(1.2f, 1.2f, 0.0f, 0.0f, 95.0f, 1.0f, 1.0f, 0.85f, 0.02f);
  pid_2     = new AC_PID(1.2f, 1.2f, 0.0f, 0.0f, 95.0f, 1.0f, 1.0f, 0.85f, 0.02f);
  pid_3     = new AC_PID(1.2f, 1.2f, 0.0f, 0.0f, 95.0f, 1.0f, 1.0f, 0.85f, 0.02f);
  pid_4     = new AC_PID(1.2f, 1.2f, 0.0f, 0.0f, 95.0f, 1.0f, 1.0f, 0.85f, 0.02f);
  motor1_fr = new AP_Motors(&htim3,        // encoder timer
                            1,             // encoder direction
                            GPIOC,         // L298N GPIO port
                            GPIO_PIN_1,    // L298N in1
                            GPIO_PIN_3,    // L298N in2
                            &htim5,        // pwm timer
                            TIM_CHANNEL_4, // pwm channel
                            99,
                            pid_1);
  motor2_fl = new AP_Motors(&htim1,        // encoder timer
                            1,             // encoder direction
                            GPIOE,         // L298N GPIO port
                            GPIO_PIN_2,    // L298N in1
                            GPIO_PIN_4,    // L298N in2
                            &htim5,        // pwm timer
                            TIM_CHANNEL_1, // pwm channel
                            99,
                            pid_2);
  motor3_bl = new AP_Motors(&htim4,        // encoder timer
                            1,             // encoder direction
                            GPIOE,         // L298N GPIO port
                            GPIO_PIN_3,    // L298N in1
                            GPIO_PIN_5,    // L298N in2
                            &htim5,        // pwm timer
                            TIM_CHANNEL_2, // pwm channel
                            99,
                            pid_3);
  motor4_br = new AP_Motors(&htim8,        // encoder timer
                            1,             // encoder direction
                            GPIOC,         // L298N GPIO port
                            GPIO_PIN_0,    // L298N in1
                            GPIO_PIN_3,    // L298N in2
                            &htim5,        // pwm timer
                            TIM_CHANNEL_3, // pwm channel
                            99,
                            pid_4);
}

void loop(void)
{
  motor1_fr -> set_rpm(50.0f);
  motor2_fl -> set_rpm(50.0f);
  motor3_bl -> set_rpm(50.0f);
  motor4_br -> set_rpm(50.0f);
}

#if (defined(__GNUC__) || defined(__CC_ARM)) && defined(__cplusplus)
}
#endif

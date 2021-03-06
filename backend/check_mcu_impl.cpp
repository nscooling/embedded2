#include <hal/uart.h>
#include <hal/gpio.h>
#include <hal/time.h>

void check_uart()
{
	uart::uart uart1;

	uart1.init(1, uart::config::_9600_8_N_1(), nullptr);

	uart1.send ("Hello from uart\n");
}

void check_gpio()
{
	gpio::gpio gpio1(PA0);


	gpio1.set_as_digital_output(gpio::PushPull);
	gpio1.set_as_digital_input(gpio::NoPull);
	gpio1.set_as_analog_input();

	gpio1.on();
	gpio1.off();
	gpio1.high();
	gpio1.low();

	gpio1.get_input_value();
}

void check_time()
{
	unsigned int res =  time::getTickCount();
	res += time::getTickPerMs();
	res += time::getTickPerUs();

	res += time::elapsedMicros(0);

	time::msleep(1000);
	time::usleep(1000);
}

int main (int argc, char** argv)
{
	check_uart();

	check_gpio();

	while (true);
	return 0;

}

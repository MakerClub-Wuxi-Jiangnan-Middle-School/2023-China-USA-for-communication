#include<WeELF328P.h>
#include<WeMultipleLineFollower.h>

//	绿植搬运任务()
void _p33kr1jscseoflngbl();
//	巡线24-速度为("speed")
void _ijlp1b2419sgvip2fga(double _speed);
//	巡线35-速度为("speed")
void _ijlp1b3519sgvip2fga(double _speed);
//	巡线24直到345-速度为("speed")
void _ijlp1b24nhwg8g34519sgvip2fga(double _speed);
//	微前进并右转()
void _iweg99sezinqgkzsbw();
//	右转直到3到线()
void _gkzsbwnhwg8g3g8gp1b();
//	巡线35直到12345-速度为("speed")
void _ijlp1b35nhwg8g1234519sgvip2fga(double _speed);
//	掉头后右转()
void _jnthmcglqgkzsbw();
//	左转直到3到线()
void _ijqsbwnhwg8g3g8gp1b();
//	巡线24直到12345-速度为("speed")
void _ijlp1b24nhwg8g1234519sgvip2fga(double _speed);
//	水电站任务()
void _ldgn5ho9lflngbl();
//	火电站任务()
void _m7fn5ho9lflngbl();
//	右转直到4到线()
void _gkzsbwnhwg8g4g8gp1b();
//	舵机-运动到角度("angle")
void _ppxke219seogbsg8gr82ip2(double _angle);
//	固碳工厂任务()
void _h6inubijpghuflngbl();
//	微前进并左转()
void _iweg99sezinqijqsbw();
//	掉头后左转()
void _jnthmcglqijqsbw();
//	巡线24直到123-速度为("speed")
void _ijlp1b24nhwg8g12319sgvip2fga(double _speed);
//	太阳能板任务()
void _hm2to3ph9kfzflngbl();
//	左转直到4到线()
void _ijqsbwnhwg8g4g8gp1b();

WeDCMotor dc_1(M1);
WeDCMotor dc_2(M2);
WeMultipleLineFollower linefollower_A(PORT_A);
Servo servo_D;
WeBuzzer buzzer(OnBoard_Buzzer);
WeUltrasonicSensor ultrasonic_B(PORT_B);
double _sgvip2 = 0;	//速度;
double _ppxke2r82ip2 = 0;	//舵机角度;
double _r82ip2g84k31 = 0;	//角度判断;

void setup(){
	servo_D.attach(PORT_D);
	pinMode(OnBoard_Button, INPUT);

	_ppxke2r82ip2 = 110;	//舵机角度
	servo_D.write(_ppxke2r82ip2/*舵机角度*/);
	_sgvip2 = 80;	//速度
	while(!(!digitalRead(OnBoard_Button)));
	delay(1000);
	buzzer.tone(262, 500);
	dc_1.run(120);
	dc_2.run(-120);
	delay(300);
	_ijlp1b24nhwg8g34519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到345-速度为
	_m7fn5ho9lflngbl();	//火电站任务
	_ijlp1b24nhwg8g34519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到345-速度为
	_ldgn5ho9lflngbl();	//水电站任务
	_ijlp1b24nhwg8g34519sgvip2fga(100);	//巡线24直到345-速度为
	_h6inubijpghuflngbl();	//固碳工厂任务
	_hm2to3ph9kfzflngbl();	//太阳能板任务
	for(int i=4; i>0; --i){
		_ijlp1b24nhwg8g34519sgvip2fga(100);	//巡线24直到345-速度为
		dc_1.run(100);
		dc_2.run(-100);
		delay(500);
	}
	_ijlp1b24nhwg8g34519sgvip2fga(100);	//巡线24直到345-速度为
	_p33kr1jscseoflngbl();	//绿植搬运任务
	dc_1.stop();
	dc_2.stop();
	_ijlp1b24nhwg8g1234519sgvip2fga(100);	//巡线24直到12345-速度为
	_ijlp1b24nhwg8g1234519sgvip2fga(100);	//巡线24直到12345-速度为
	dc_1.stop();
	dc_2.stop();
	for(int i=3; i>0; --i){
		buzzer.tone(73, 500);
		delay(200);
	}
	for(int i=3; i>0; --i){
		ultrasonic_B.setColor(3, 226, 2, 2);
		delay(200);
		ultrasonic_B.setColor(3, 226, 226, 226);
		delay(200);
	}
}

void loop(){
}

//	绿植搬运任务()
void _p33kr1jscseoflngbl(){
	_iweg99sezinqgkzsbw();	//微前进并右转
	_gkzsbwnhwg8g3g8gp1b();	//右转直到3到线
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.run(80);
	dc_2.run(-80);
	delay(450);
	dc_1.run(-80);
	dc_2.run(80);
	delay(400);
	_jnthmcglqgkzsbw();	//掉头后右转
}

//	巡线24-速度为("speed")
void _ijlp1b2419sgvip2fga(double _speed){
	linefollower_A.readSensor();
	if(linefollower_A.readSensor2() == 0 && linefollower_A.readSensor4() == 0){
		dc_1.run(_speed);
		dc_2.run(-_speed);
	}else if(linefollower_A.readSensor2() == 1 && linefollower_A.readSensor4() == 0){
		dc_1.run(_speed);
		dc_2.run(_speed);
	}else if(linefollower_A.readSensor2() == 0 && linefollower_A.readSensor4() == 1){
		dc_1.run(-_speed);
		dc_2.run(-_speed);
	}
}

//	巡线35-速度为("speed")
void _ijlp1b3519sgvip2fga(double _speed){
	linefollower_A.readSensor();
	if(linefollower_A.readSensor3() == 0 && linefollower_A.readSensor5() == 0){
		dc_1.run(_speed);
		dc_2.run(-_speed);
	}else if(linefollower_A.readSensor3() == 1 && linefollower_A.readSensor5() == 0){
		dc_1.run(_speed);
		dc_2.run(_speed);
	}else if(linefollower_A.readSensor3() == 0 && linefollower_A.readSensor5() == 1){
		dc_1.run(-_speed);
		dc_2.run(-_speed);
	}else if(linefollower_A.readSensor3() == 1 && linefollower_A.readSensor5() == 1){
		dc_1.run(-_speed);
		dc_2.run(-_speed);
	}
}

//	巡线24直到345-速度为("speed")
void _ijlp1b24nhwg8g34519sgvip2fga(double _speed){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor3() == 1 && (linefollower_A.readSensor4() == 1 && linefollower_A.readSensor5() == 1))){
		_ijlp1b2419sgvip2fga(_speed);	//巡线24-速度为
	}
}

//	微前进并右转()
void _iweg99sezinqgkzsbw(){
	dc_1.run(95);
	dc_2.run(-95);
	delay(300);
	dc_1.run(-100);
	dc_2.run(-100);
	delay(400);
}

//	右转直到3到线()
void _gkzsbwnhwg8g3g8gp1b(){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor3() == 1 && linefollower_A.readSensor4() == 0)){
		linefollower_A.readSensor();
		dc_1.run(-80);
		dc_2.run(-80);
	}
}

//	巡线35直到12345-速度为("speed")
void _ijlp1b35nhwg8g1234519sgvip2fga(double _speed){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor1() == 1 && (linefollower_A.readSensor2() == 1 && (linefollower_A.readSensor3() == 1 && (linefollower_A.readSensor4() == 1 && linefollower_A.readSensor5() == 1))))){
		_ijlp1b3519sgvip2fga(_speed);	//巡线35-速度为
	}
}

//	掉头后右转()
void _jnthmcglqgkzsbw(){
	dc_1.run(-80);
	dc_2.run(80);
	delay(700);
	dc_1.run(80);
	dc_2.run(80);
	delay(500);
	_ijqsbwnhwg8g3g8gp1b();	//左转直到3到线
}

//	左转直到3到线()
void _ijqsbwnhwg8g3g8gp1b(){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor2() == 0 && linefollower_A.readSensor3() == 1)){
		linefollower_A.readSensor();
		dc_1.run(80);
		dc_2.run(80);
	}
}

//	巡线24直到12345-速度为("speed")
void _ijlp1b24nhwg8g1234519sgvip2fga(double _speed){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor1() == 1 && (linefollower_A.readSensor2() == 1 && (linefollower_A.readSensor3() == 1 && (linefollower_A.readSensor4() == 1 && linefollower_A.readSensor5() == 1))))){
		_ijlp1b2419sgvip2fga(_speed);	//巡线24-速度为
	}
}

//	水电站任务()
void _ldgn5ho9lflngbl(){
	_iweg99sezinqgkzsbw();	//微前进并右转
	_gkzsbwnhwg8g4g8gp1b();	//右转直到4到线
	_ijlp1b35nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线35直到12345-速度为
	dc_1.stop();
	dc_2.stop();
	servo_D.write(120);
	delay(200);
	dc_1.run(75);
	dc_2.run(75);
	delay(500);
	dc_1.run(20);
	dc_2.run(-20);
	delay(100);
	servo_D.write(90);
	delay(200);
	dc_1.run(-80);
	dc_2.run(-80);
	delay(600);
	dc_1.run(-80);
	dc_2.run(80);
	delay(400);
	dc_1.stop();
	dc_2.stop();
	dc_1.run(80);
	dc_2.run(80);
	delay(500);
	_jnthmcglqgkzsbw();	//掉头后右转
}

//	火电站任务()
void _m7fn5ho9lflngbl(){
	_iweg99sezinqgkzsbw();	//微前进并右转
	_gkzsbwnhwg8g4g8gp1b();	//右转直到4到线
	_ijlp1b35nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线35直到12345-速度为
	dc_1.run(15);
	dc_2.run(-15);
	delay(100);
	dc_1.run(80);
	dc_2.run(80);
	delay(300);
	dc_1.stop();
	dc_2.stop();
	_ppxke2r82ip2 = 90;	//舵机角度
	servo_D.write(_ppxke2r82ip2/*舵机角度*/);
	dc_1.run(-100);
	dc_2.run(-100);
	delay(800);
	dc_1.run(80);
	dc_2.run(80);
	delay(200);
	servo_D.write(120);
	_jnthmcglqgkzsbw();	//掉头后右转
}

//	右转直到4到线()
void _gkzsbwnhwg8g4g8gp1b(){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor4() == 1 && linefollower_A.readSensor5() == 0)){
		linefollower_A.readSensor();
		dc_1.run(-80);
		dc_2.run(-80);
	}
}

//	舵机-运动到角度("angle")
void _ppxke219seogbsg8gr82ip2(double _angle){
	_r82ip2g84k31 = _ppxke2r82ip2/*舵机角度*/ > _angle;	//角度判断
	while(!(abs(_ppxke2r82ip2/*舵机角度*/ - _angle) == 0)){
		if(_r82ip2g84k31/*角度判断*/ == 1){
			_ppxke2r82ip2 += -1;	//舵机角度
		}else{
			_ppxke2r82ip2 += 1;	//舵机角度
		}
		servo_D.write(_ppxke2r82ip2/*舵机角度*/);
		delay(50);
	}
}

//	固碳工厂任务()
void _h6inubijpghuflngbl(){
	_iweg99sezinqgkzsbw();	//微前进并右转
	_gkzsbwnhwg8g3g8gp1b();	//右转直到3到线
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.run(100);
	dc_2.run(-100);
	delay(200);
	_ijlp1b24nhwg8g12319sgvip2fga(_sgvip2/*速度*/);	//巡线24直到123-速度为
	dc_1.run(100);
	dc_2.run(-100);
	delay(200);
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	_iweg99sezinqijqsbw();	//微前进并左转
	_ijqsbwnhwg8g3g8gp1b();	//左转直到3到线
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.run(80);
	dc_2.run(-80);
	delay(200);
	dc_1.stop();
	dc_2.stop();
	_ppxke2r82ip2 = 50;	//舵机角度
	servo_D.write(_ppxke2r82ip2/*舵机角度*/);
	dc_1.run(80);
	dc_2.run(80);
	delay(1500);
	_ijqsbwnhwg8g3g8gp1b();	//左转直到3到线
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.run(80);
	dc_2.run(-80);
	delay(300);
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.run(80);
	dc_2.run(-80);
	delay(450);
	dc_1.stop();
	dc_2.stop();
	_ppxke2r82ip2 = 110;	//舵机角度
	servo_D.write(_ppxke2r82ip2/*舵机角度*/);
	dc_1.run(-80);
	dc_2.run(80);
	delay(400);
	_jnthmcglqijqsbw();	//掉头后左转
	_ijlp1b24nhwg8g34519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到345-速度为
	_iweg99sezinqgkzsbw();	//微前进并右转
	_gkzsbwnhwg8g3g8gp1b();	//右转直到3到线
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.stop();
	dc_2.stop();
	_ppxke2r82ip2 = 50;	//舵机角度
	servo_D.write(_ppxke2r82ip2/*舵机角度*/);
	_iweg99sezinqijqsbw();	//微前进并左转
	_ijqsbwnhwg8g4g8gp1b();	//左转直到4到线
}

//	微前进并左转()
void _iweg99sezinqijqsbw(){
	dc_1.run(95);
	dc_2.run(-95);
	delay(300);
	dc_1.run(100);
	dc_2.run(100);
	delay(400);
}

//	掉头后左转()
void _jnthmcglqijqsbw(){
	dc_1.run(-80);
	dc_2.run(80);
	delay(800);
	dc_1.run(-80);
	dc_2.run(-80);
	delay(500);
	_gkzsbwnhwg8g3g8gp1b();	//右转直到3到线
}

//	巡线24直到123-速度为("speed")
void _ijlp1b24nhwg8g12319sgvip2fga(double _speed){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor1() == 1 && (linefollower_A.readSensor2() == 1 && linefollower_A.readSensor3() == 1))){
		_ijlp1b2419sgvip2fga(_speed);	//巡线24-速度为
	}
}

//	太阳能板任务()
void _hm2to3ph9kfzflngbl(){
	_ijlp1b24nhwg8g12319sgvip2fga(_sgvip2/*速度*/);	//巡线24直到123-速度为
	dc_1.run(60);
	dc_2.run(60);
	delay(100);
	dc_1.run(100);
	dc_2.run(-100);
	delay(200);
	dc_1.stop();
	dc_2.stop();
	_ppxke219seogbsg8gr82ip2(70);	//舵机-运动到角度
	dc_1.run(80);
	dc_2.run(-80);
	delay(300);
	dc_1.run(80);
	dc_2.run(80);
	delay(800);
	_ijqsbwnhwg8g3g8gp1b();	//左转直到3到线
	_ijlp1b24nhwg8g1234519sgvip2fga(_sgvip2/*速度*/);	//巡线24直到12345-速度为
	dc_1.run(-80);
	dc_2.run(80);
	delay(200);
	dc_1.stop();
	dc_2.stop();
	_ppxke219seogbsg8gr82ip2(50);	//舵机-运动到角度
	_jnthmcglqgkzsbw();	//掉头后右转
	_ppxke2r82ip2 = 110;	//舵机角度
	servo_D.write(_ppxke2r82ip2/*舵机角度*/);
}

//	左转直到4到线()
void _ijqsbwnhwg8g4g8gp1b(){
	linefollower_A.readSensor();
	while(!(linefollower_A.readSensor3() == 0 && linefollower_A.readSensor4() == 1)){
		linefollower_A.readSensor();
		dc_1.run(80);
		dc_2.run(80);
	}
}

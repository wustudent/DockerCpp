#include <systemc.h>

#ifndef CONSUMER_H_
#define CONSUMER_H_

SC_MODULE(Consumer){

	sc_in<int> data;

	int readNumber;

	SC_CTOR(Consumer){
		SC_METHOD(consume);
		sensitive << data;
	}

	void consume()
	{
		readNumber = data.read();
		//readNumber = data; //geht bei SC_SIGNAL auch
		cout << "[" << sc_time_stamp() << " / " << sc_delta_count() << "](" << name() << "): read " << readNumber << endl;
	}

};

#endif

 


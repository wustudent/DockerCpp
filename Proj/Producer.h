#include <systemc.h>

#ifndef PRODUCER_H_
#define PRODUCER_H_

SC_MODULE(Producer){

	sc_out<int> data;

	int generatedNumber;
	int i;

	SC_CTOR(Producer){
		data.initialize(42); //initialisiert den Ausgangsport mit dem angegebenen Wert (ansonsten 0)
		SC_THREAD(produce);
	}

	void produce()
	{
		i = 0;
		while(i < 10) {
			generatedNumber = rand();
			cout << "[" << sc_time_stamp() << "](" << name() << "): generated " << generatedNumber << endl;
			data.write(generatedNumber);
			//data = generatedNumber; //geht bei SC_SIGNAL auch

			wait(SC_ZERO_TIME); //sonst kommt der Consumer nie dran
			i++;
		}
	}

};

#endif

 


#ifndef EVENT_H
#define EVENT_H
#include<string>
using namespace std;

/**
 * Models a discrete event.
 */
class Event {
	public:
		Event(double time, string description);
        virtual ~Event();
		double get_time()const;
		double get_time_later()const;
		virtual void act();
		string get_description()const;

	private:
		double time;
		string description;
};

/**
 * Used by the priority queue to compare Event* variables. 
 * Larger value is the Event* whose Event pointee having the earlier time.
 */
class mycomparison
{
  public:
	mycomparison(){}
  bool operator() (Event* e1, Event* e2) const {
    return e1->get_time() > e2->get_time();
  }
};

#endif
#pragma once
#include "vector.h"
#include "event.h"

using namespace std;

class Dialog :
	public Vector {
protected:
	int EndState;
public:
	Dialog();
	virtual ~Dialog();
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
};
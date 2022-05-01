#pragma once
//function pointer
#include <functional>
#include <map>
#include <vector>
#include <algorithm>



template <typename T>
class Event {
protected:
	T _type;
	std::string _name;
	bool _handled = false;
public:
	Event() = default;
	Event(T type, const std::string& name = "") : _type(type), _name(name) {};
	inline const T type() const { return _type; };
	inline const std::string& getName() const { return _name; };
	virtual bool isHandled() { return _handled; };
private:
};



template<typename T>
class Dispatcher {
private:
	using SlotType = std::function<void(const Event<T>&)>;
	std::map<T, std::vector<SlotType>> _observers;
public:

	/**
	 * Subscribe an observer
	 * @param type  The type of the function to listen to.
	 * @param funct function of the observer
	 */
	void subscribe(T type, const SlotType& funct) {
		_observers[type].push_back(funct);
	};

	/**
	 * Send the event to all the observers
	 * @param event event to post
	 */
	void post(Event<T>& event) {
		if (_observers.find(event.type()) == _observers.end())
			return;

		//Loop though all observers. If the event is not handled yet we continue to process it.
		for (auto&& observer : _observers.at(event.type())) {
			if (!event.isHandled()) observer(event);
		}
	};
private:
};


enum class EventType1 {
	TEST_EVENT,
	TEST_EVENT2,
	TEST_EVENT3
};

enum class EventType2 {
	TEST_EVENT,
	TEST_EVENT2,
	TEST_EVENT3
};

class DemoEvent : public Event<EventType1>
{
public:
	DemoEvent() : Event<EventType1>(EventType1::TEST_EVENT, "DemoEvent") {};
	virtual ~DemoEvent() = default;
};

class DemoEventAlt : public Event<EventType2>
{
private:
public:
	DemoEventAlt() : Event<EventType2>(EventType2::TEST_EVENT, "DemoEventAlt") {};
	virtual ~DemoEventAlt() = default;
};
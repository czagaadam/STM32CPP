/*
 * ISRbase.h
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  A simple implementation of a generic storage class with std::vector<T*>
 *
 */

#ifndef ISRBASE_H_
#define ISRBASE_H_

#include <vector>
#include <algorithm>


template <class T>
class ISRbase
{
public:
	ISRbase()
	{
		ISR_LIST.clear();
	}
	~ISRbase()
	{
		if(ISR_LIST.size() == 0)
		{
			return;
		}
		ISR_LIST.clear();
	}
	void add(T* obj)
	{
		ISR_LIST.push_back(obj);
	}
	void remove(T* obj)
	{
		if(ISR_LIST.size() == 0)
		{
			return;
		}
		ISR_LIST.erase(std::find(ISR_LIST.begin(),ISR_LIST.end(),obj));
	}

	T* get(uint16_t index)
	{
		if(ISR_LIST.size() == 0)
		{
			return NULL;
		}
		return ISR_LIST[index];
	}

	size_t size()
	{
		return ISR_LIST.size();
	}


protected:

private:
	std::vector<T*> ISR_LIST;

};

//implementation without vector
/*
template <class T>
class ISRbase
{
	public:
	ISRbase(void)  	{Count = 0;}
	~ISRbase(void)	{
		//#todo:
	}
	//T * needed because passing "this" special pointer to function
	void add(T * const & obj)
	{
		if (Count < MAX_DIN_COUNT) Storage[Count++] = obj;
		//#todo: else
	}
	//void remove(T& obj)
	void remove(T* obj)
	{
		//#todo:
	}
	T* get(uint8_t index)
	{
		if (index >= 0 && index < Count)	return Storage[index];
		//#todo: else
	}
	uint8_t get_size(void)
	{
		return Count;
	}
	private:
	uint8_t Count;
	static const uint8_t MAX_DIN_COUNT = 24;
	T* Storage[MAX_DIN_COUNT];
};
*/

#endif /* ISRBASE_H_ */

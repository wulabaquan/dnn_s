#pragma once
#include "util.h"
namespace nn {
	class layer{
	public:
		layer(int in, int out):prev_(0),next_(0)
		{

		 }
		void connect(layer* tail)
		{
			//dimension mismatch
			if (this->out_dim() != tail->in_dim())
				throw std::domain_error("dimension mismatch");
			next_ = tail;
			tail->prev_ = this;
		}

		int in_dim()const { return in; }
		int out_dim()const { return out; }


	private:
		layer* prev_;
		layer* next_;

		//own
		int in;
		int out;
	};
	class layers {
	public:
		layers():head_(0),tail_(0) {};
		~layers() {};

		void add(layer* new_tail)
		{
			if (!head_)
				head_= new_tail;

			tail_ = new_tail;


		}
	private:
		layer* head_;
		layer* tail_;
	};
}
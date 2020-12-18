#pragma once

#include "layer.h"
namespace nn {
	class cnn {
	public:
		cnn() {}
		~cnn() {};

		void add(layer* layer)
		{
			layers_.add(layer);
		}
	private:
		layer layers_;
	};
}
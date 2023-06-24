#include "rosneuro_integrator_dynamic/Dynamic.h"

namespace rosneuro {
	namespace integrator {

Dynamic::Dynamic(void) : p_nh_("~") {
	this->setname("dynamic");
	//this->data_ = this->uniform_vector(0.5f);
}

Dynamic::~Dynamic(void) {
}

bool Dynamic::configure(void) {


	this->pubfld_ = this->p_nh_.advertise<std_msgs::Float64>("dynamicfield", 1);

	return true;
}

Eigen::VectorXf Dynamic::apply(const Eigen::VectorXf& input) {

}

bool Dynamic::reset(void) {
	//this->data_ = this->uniform_vector(0.5f);
	return true;
}

Eigen::VectorXf Dynamic::uniform_vector(float value) {
	return Eigen::Vector2f::Constant(value);
}

void Dynamic::add(float mu, float lambda, float sigma) {

	FieldPoint point;
	point.mu 	 = mu;
	point.lambda = lambda;
	point.sigma  = sigma;
	this->add(point);
}

void Dynamic::add(const FieldPoint& point) {

	if(point.mu < this->support_min_ || point.mu > this->support_max_) {
		return;
	}

	this->field_.push_back(point);
}

void Dynamic::clear(void) {
	this->field_.clear();
}


//void Dynamic::on_request_reconfigure(rosneuro_config_exponential &config, uint32_t level) {
//
//}

	}

}


#ifndef ROSNEURO_INTEGRATOR_DYNAMIC_H_
#define ROSNEURO_INTEGRATOR_DYNAMIC_H_

#include <Eigen/Dense>
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <pluginlib/class_list_macros.h>
//#include <dynamic_reconfigure/server.h>

#include "rosneuro_integrator/GenericIntegrator.h"
//#include "rosneuro_integrator_exponential/DynamicConfig.h"


namespace rosneuro {
	namespace integrator {

class FieldPoint {
	public:
		float mu;
		float sigma;
		float lambda;

};

//using rosneuro_config_dynamic = rosneuro_integrator_dynamic::DynamicConfig;
//using dyncfg_dynamic          = dynamic_reconfigure::Server<rosneuro_config_dynamic>;

class Dynamic : public GenericIntegrator {

	public:
		Dynamic(void);
		~Dynamic(void);


		bool configure(void);
		Eigen::VectorXf apply(const Eigen::VectorXf& input);
		bool reset(void);

		void add(const FieldPoint& point);
		void add(float mu, float lambda, float sigma);
		void clear(void);


	private:
		Eigen::VectorXf uniform_vector(float value);
		//void on_request_reconfigure(rosneuro_config_dynamic &config, uint32_t level);

	private:
		ros::NodeHandle p_nh_;
		ros::Publisher 	pubfld_;

		std::vector<FieldPoint>		field_;
		const float support_min_ = 0.0f;
		const float support_max_ = 1.0f;

		//dyncfg_dynamic recfg_srv_;
  		//dyncfg_dynamic::CallbackType recfg_callback_type_;
		


};

PLUGINLIB_EXPORT_CLASS(rosneuro::integrator::Dynamic, rosneuro::integrator::GenericIntegrator)

	}
}

#endif

#ifndef DYNAMIC_GRAPH_JOINT_STATE_HH
# define DYNAMIC_GRAPH_JOINT_STATE_HH
# include <dynamic-graph/entity.h>
# include <dynamic-graph/signal-ptr.h>
# include <dynamic-graph/signal-time-dependent.h>

# include <ros/ros.h>
# include <sensor_msgs/JointState.h>

# include "converter.hh"
# include "sot_to_ros.hh"

namespace dynamicgraph
{
  /// \brief Publish current robot configuration to ROS.
  class RosJointState : public dynamicgraph::Entity
  {
    DYNAMIC_GRAPH_ENTITY_DECL();
  public:
    /// \brief Vector input signal.
    typedef SignalPtr<ml::Vector, int> signalVectorIn_t;

    RosJointState (const std::string& n);
    virtual ~RosJointState ();

    int& trigger (int&, int);
  private:
    ros::NodeHandle nh_;
    signalVectorIn_t state_;
    ros::Publisher publisher_;
    sensor_msgs::JointState jointState_;
    dynamicgraph::SignalTimeDependent<int,int> trigger_;
  };
} // end of namespace dynamicgraph.

#endif //! DYNAMIC_GRAPH_JOINT_STATE_HH

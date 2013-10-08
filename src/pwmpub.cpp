#include "ros/ros.h"
#include "std_msgs/Char.h"
#include "setup.h"
#include <sstream>
#include <string>
#include <unistd.h>
#include <termios.h>


int main(int argc, char **argv){
  
  ros::init(argc, argv, "input");
  ros::NodeHandle n;
  ros::Publisher pwm_pub = n.advertise<std_msgs::Char>("pwm", 1000);

ros::Rate loop_rate(10);

  int count = 0;
  setup();
  while (ros::ok()){
	 
    
    std_msgs::Char msg; 	
     unsigned char pwm;
   
		pwm=getchar();
		
                
		if(pwm=='p') {
			return 0;
		}
		msg.data=pwm;
        pwm_pub.publish(msg);
        std::cout<<msg.data<<" ";

    ros::spinOnce();

    //loop_rate.sleep();
    ++count;
  }
  /* restore the former settings */
	tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);


  return 0;
}

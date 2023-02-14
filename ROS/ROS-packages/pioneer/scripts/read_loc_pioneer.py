import rospy
from std_msgs.msg import String,Bool,Int16
from geometry_msgs.msg import Pose2D
import numpy as np
import time
import matplotlib.pyplot as plt

def get_pioneer_pose(data):
    rospy.loginfo("I heared {}".format((data.theta*(180/np.pi))))
    plt.plot(data.x,data.y,marker=(4,1,data.theta*(180/np.pi)-90),markersize=20,linestyle='None',color='green')
    plt.axis('equal')
    plt.draw()
    plt.pause(0.01)

def listener():
    rospy.init_node('pioneer_pose',anonymous=True)
    rospy.Subscriber("pioneer_loc",Pose2D,get_pioneer_pose)
    rospy.spin()
    if (rospy.is_shutdown()==True):
            print("\nBye Bye Digimon from listener I will miss you :(")

if __name__=='__main__':
    try:
        listener()
    except rospy.ROSInterruptException:
        pass
import rospy
from std_msgs.msg import String,Bool,Int16
from mymsgs.msg import v2v

def replay(iformation):
    rospy.loginfo("\nyour car \n%s\n",iformation)

def listener():
    rospy.init_node('listener',anonymous=True)
    rospy.Subscriber("car_channel",v2v,replay)
    rospy.spin()
    if (rospy.is_shutdown()==True):
            print("\nBye Bye Digimon from listener I will miss you :(")

if __name__=='__main__':
    try:
        listener()
    except rospy.ROSInterruptException:
        pass
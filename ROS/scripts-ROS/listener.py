import rospy
from std_msgs.msg import String,Bool,Int16

def replay(message):
    rospy.loginfo("I heared %s",message.data)

def listener():
    rospy.init_node('listener',anonymous=True)
    rospy.Subscriber("chatter",String,replay)
    rospy.spin()
    if (rospy.is_shutdown()==True):
            print("\nBye Bye Digimon from listener I will miss you :(")

if __name__=='__main__':
    try:
        listener()
    except rospy.ROSInterruptException:
        pass
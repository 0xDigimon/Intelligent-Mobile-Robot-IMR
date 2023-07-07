import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('chatter',String,queue_size=10) 
    rospy.init_node('talker',anonymous=True)
    rate=rospy.Rate(5)
    while not rospy.is_shutdown():
        message= "hello oxDigimon Time is %s"%rospy.get_time()
        rospy.loginfo(message)
        pub.publish(message)
        rate.sleep()
        if (rospy.is_shutdown()==True):
            print("\nBye Bye Digimon from talker I will miss you :(")


if __name__=='__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
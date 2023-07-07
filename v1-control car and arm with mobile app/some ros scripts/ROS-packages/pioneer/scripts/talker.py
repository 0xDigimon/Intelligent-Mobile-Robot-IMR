import rospy
from std_msgs.msg import String
from mymsgs.msg import v2v
def talker():
    car_pub = rospy.Publisher('car_channel',v2v,queue_size=10) 
    rospy.init_node('talker',anonymous=True)
    rate=rospy.Rate(1)
    pioneer_car_info=v2v()
    pioneer_car_info.id=6476
    pioneer_car_info.name="Tesla"
    pioneer_car_info.battery_level=60
    pioneer_car_info.car_pose.x=4
    pioneer_car_info.car_pose.y=5
    pioneer_car_info.car_pose.theta=60
    pioneer_car_info.car_speed.linear.x=50
    pioneer_car_info.car_speed.linear.y=100
    pioneer_car_info.car_speed.linear.z=80
    pioneer_car_info.car_speed.angular.x=5
    pioneer_car_info.car_speed.angular.y=10
    pioneer_car_info.car_speed.angular.z=8
    while not rospy.is_shutdown():
        #message= "hello oxDigimon Time is %s"%rospy.get_time()
        #rospy.loginfo(message)

        car_pub.publish(pioneer_car_info)
        rate.sleep()
        if (rospy.is_shutdown()==True):
            print("\nBye Bye Digimon from talker I will miss you :(")


if __name__=='__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
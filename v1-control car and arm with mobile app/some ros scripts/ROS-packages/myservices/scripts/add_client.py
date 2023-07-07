from myservices.srv import *
import time
import rospy


def add_two_ints_client(x,y):
    rospy.wait_for_service('add_two_num')
    try:
        add_two_num=rospy.ServiceProxy('add_two_num',add_two_ints)
        resp1=add_two_num(x,y)
        return resp1.sum
    except rospy.ServiceException as e:
        print("service call failed: %s"%e)

if __name__=="__main__":
    if len(sys.argv)==3:
        x=int(sys.argv[1])
        y=int(sys.argv[2])
    else:
        sys.exit(1)
    print("requesting %s+%s"%(x,y))
    print("%s+%s=%s"%(x,y,add_two_ints_client(x,y)))
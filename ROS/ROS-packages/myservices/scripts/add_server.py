from myservices.srv import *
import time
import rospy
def handle_add_two_ints(req):
    print("Returning [%s+%s=%s]"%(req.a,req.b,(req.a+req.b)))
    time.sleep(5)
    sum_response=add_two_intsResponse(req.a+req.b)
    return sum_response
def add_two_ints_server():
    rospy.init_node('add_two_ints_server')
    s=rospy.Service('add_two_num',add_two_ints,handle_add_two_ints)
    print("ready to add two ints")
    rospy.spin()
if __name__=="__main__":
    add_two_ints_server()
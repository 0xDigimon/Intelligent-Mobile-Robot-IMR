#ifndef _ROS_SERVICE_RequestTransformStream_h
#define _ROS_SERVICE_RequestTransformStream_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace tf2_server
{

static const char REQUESTTRANSFORMSTREAM[] = "tf2_server/RequestTransformStream";

  class RequestTransformStreamRequest : public ros::Msg
  {
    public:
      typedef const char* _parent_frame_type;
      _parent_frame_type parent_frame;
      uint32_t child_frames_length;
      typedef char* _child_frames_type;
      _child_frames_type st_child_frames;
      _child_frames_type * child_frames;
      typedef bool _intermediate_frames_type;
      _intermediate_frames_type intermediate_frames;
      typedef ros::Duration _publication_period_type;
      _publication_period_type publication_period;
      typedef bool _allow_transforms_update_type;
      _allow_transforms_update_type allow_transforms_update;
      typedef int32_t _publisher_queue_size_type;
      _publisher_queue_size_type publisher_queue_size;
      typedef const char* _requested_topic_name_type;
      _requested_topic_name_type requested_topic_name;
      typedef const char* _requested_static_topic_name_type;
      _requested_static_topic_name_type requested_static_topic_name;

    RequestTransformStreamRequest():
      parent_frame(""),
      child_frames_length(0), st_child_frames(), child_frames(nullptr),
      intermediate_frames(0),
      publication_period(),
      allow_transforms_update(0),
      publisher_queue_size(0),
      requested_topic_name(""),
      requested_static_topic_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_parent_frame = strlen(this->parent_frame);
      varToArr(outbuffer + offset, length_parent_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->parent_frame, length_parent_frame);
      offset += length_parent_frame;
      *(outbuffer + offset + 0) = (this->child_frames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->child_frames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->child_frames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->child_frames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->child_frames_length);
      for( uint32_t i = 0; i < child_frames_length; i++){
      uint32_t length_child_framesi = strlen(this->child_frames[i]);
      varToArr(outbuffer + offset, length_child_framesi);
      offset += 4;
      memcpy(outbuffer + offset, this->child_frames[i], length_child_framesi);
      offset += length_child_framesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_intermediate_frames;
      u_intermediate_frames.real = this->intermediate_frames;
      *(outbuffer + offset + 0) = (u_intermediate_frames.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->intermediate_frames);
      *(outbuffer + offset + 0) = (this->publication_period.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->publication_period.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->publication_period.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->publication_period.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->publication_period.sec);
      *(outbuffer + offset + 0) = (this->publication_period.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->publication_period.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->publication_period.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->publication_period.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->publication_period.nsec);
      union {
        bool real;
        uint8_t base;
      } u_allow_transforms_update;
      u_allow_transforms_update.real = this->allow_transforms_update;
      *(outbuffer + offset + 0) = (u_allow_transforms_update.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_transforms_update);
      union {
        int32_t real;
        uint32_t base;
      } u_publisher_queue_size;
      u_publisher_queue_size.real = this->publisher_queue_size;
      *(outbuffer + offset + 0) = (u_publisher_queue_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_publisher_queue_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_publisher_queue_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_publisher_queue_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->publisher_queue_size);
      uint32_t length_requested_topic_name = strlen(this->requested_topic_name);
      varToArr(outbuffer + offset, length_requested_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->requested_topic_name, length_requested_topic_name);
      offset += length_requested_topic_name;
      uint32_t length_requested_static_topic_name = strlen(this->requested_static_topic_name);
      varToArr(outbuffer + offset, length_requested_static_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->requested_static_topic_name, length_requested_static_topic_name);
      offset += length_requested_static_topic_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_parent_frame;
      arrToVar(length_parent_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parent_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parent_frame-1]=0;
      this->parent_frame = (char *)(inbuffer + offset-1);
      offset += length_parent_frame;
      uint32_t child_frames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      child_frames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      child_frames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      child_frames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->child_frames_length);
      if(child_frames_lengthT > child_frames_length)
        this->child_frames = (char**)realloc(this->child_frames, child_frames_lengthT * sizeof(char*));
      child_frames_length = child_frames_lengthT;
      for( uint32_t i = 0; i < child_frames_length; i++){
      uint32_t length_st_child_frames;
      arrToVar(length_st_child_frames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_child_frames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_child_frames-1]=0;
      this->st_child_frames = (char *)(inbuffer + offset-1);
      offset += length_st_child_frames;
        memcpy( &(this->child_frames[i]), &(this->st_child_frames), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_intermediate_frames;
      u_intermediate_frames.base = 0;
      u_intermediate_frames.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->intermediate_frames = u_intermediate_frames.real;
      offset += sizeof(this->intermediate_frames);
      this->publication_period.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->publication_period.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->publication_period.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->publication_period.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->publication_period.sec);
      this->publication_period.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->publication_period.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->publication_period.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->publication_period.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->publication_period.nsec);
      union {
        bool real;
        uint8_t base;
      } u_allow_transforms_update;
      u_allow_transforms_update.base = 0;
      u_allow_transforms_update.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_transforms_update = u_allow_transforms_update.real;
      offset += sizeof(this->allow_transforms_update);
      union {
        int32_t real;
        uint32_t base;
      } u_publisher_queue_size;
      u_publisher_queue_size.base = 0;
      u_publisher_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_publisher_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_publisher_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_publisher_queue_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->publisher_queue_size = u_publisher_queue_size.real;
      offset += sizeof(this->publisher_queue_size);
      uint32_t length_requested_topic_name;
      arrToVar(length_requested_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_requested_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_requested_topic_name-1]=0;
      this->requested_topic_name = (char *)(inbuffer + offset-1);
      offset += length_requested_topic_name;
      uint32_t length_requested_static_topic_name;
      arrToVar(length_requested_static_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_requested_static_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_requested_static_topic_name-1]=0;
      this->requested_static_topic_name = (char *)(inbuffer + offset-1);
      offset += length_requested_static_topic_name;
     return offset;
    }

    virtual const char * getType() override { return REQUESTTRANSFORMSTREAM; };
    virtual const char * getMD5() override { return "a7c59a6e27bac6bb75c581e511c7bdba"; };

  };

  class RequestTransformStreamResponse : public ros::Msg
  {
    public:
      typedef const char* _topic_name_type;
      _topic_name_type topic_name;
      typedef const char* _static_topic_name_type;
      _static_topic_name_type static_topic_name;

    RequestTransformStreamResponse():
      topic_name(""),
      static_topic_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_topic_name = strlen(this->topic_name);
      varToArr(outbuffer + offset, length_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      uint32_t length_static_topic_name = strlen(this->static_topic_name);
      varToArr(outbuffer + offset, length_static_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->static_topic_name, length_static_topic_name);
      offset += length_static_topic_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_topic_name;
      arrToVar(length_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
      uint32_t length_static_topic_name;
      arrToVar(length_static_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_static_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_static_topic_name-1]=0;
      this->static_topic_name = (char *)(inbuffer + offset-1);
      offset += length_static_topic_name;
     return offset;
    }

    virtual const char * getType() override { return REQUESTTRANSFORMSTREAM; };
    virtual const char * getMD5() override { return "42ea15d06263d0e97103be7c351c819e"; };

  };

  class RequestTransformStream {
    public:
    typedef RequestTransformStreamRequest Request;
    typedef RequestTransformStreamResponse Response;
  };

}
#endif

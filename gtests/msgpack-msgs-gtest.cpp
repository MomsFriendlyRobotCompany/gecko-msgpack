#include <gtest/gtest.h> // googletest header file
#include "gecko/gecko.hpp"
#include "gecko/msgpack/msgs.hpp"
#include <string>
#include <tuple>
#include <vector>
#include <any>

using namespace std;

// ASSERT_THROW(statement,exception_type)
// ASSERT_ANY_THROW(statement)
// ASSERT_NO_THROW(statement)
// ASSERT_TRUE(statement)


// TEST(msgpack, all) {
//     // tuple msgs = {vec_t}
//     vector<any> msgs = {
//         vec_t(1,2,3)
//     };
//
//     for (auto& m: msgs){
//         zmq::message_t msg = m.pack();
//         auto a(msg);
//         ASSERT_EQ(m, a);
//     }
// }

template<class T>
void msg(T a){
    zmq::message_t msg = a.pack();
    T c(msg);
    ASSERT_EQ(a,c);
    // ASSERT_FALSE(a == b);
    // ASSERT_FALSE(c == b);
    // ASSERT_TRUE(a == c);
}

template<class T>
void msg_st(T a){
    zmq::message_t msg = a.pack();
    T c(msg);
    ASSERT_EQ(a,c);
    ASSERT_EQ(a.timestamp, c.timestamp);
    // ASSERT_FALSE(a == b);
    // ASSERT_FALSE(c == b);
    // ASSERT_TRUE(a == c);
}

TEST(msgpack, vec_t) {
    msg<vec_t>(vec_t(1,-2,0.33));
}

TEST(msgpack, quaternion_t) {
    quaternion_t a(1,2,3.3,4);
    msg<quaternion_t>(a);
}

TEST(msgpack, twist_t) {
    vec_t v(1,1,1);
    twist_t a(v,v);
    msg<twist_t>(a);
}

TEST(msgpack, pose_t) {
    vec_t v(1,1,1);
    quaternion_t q(1,0,0,0);
    pose_t a(v,q);
    msg<pose_t>(a);
}

TEST(msgpack, wrench_t) {
    vec_t v(1,1,1);
    wrench_t a(v,v);
    msg<wrench_t>(a);
}

// TEST(msgpack, twist_st) {
//     vec_t v(1, 1, 1);
//     twist_st a(v, v), b(v, v), c;
//     ASSERT_EQ(a,b);
//     ASSERT_FALSE(a == c);
//
//     MsgPack<twist_st> buffer;
//     zmq::message_t msg = buffer.pack(a);
//     c = buffer.unpack(msg);
//     ASSERT_EQ(a, c);
//     ASSERT_EQ(a.timestamp, c.timestamp);
// }
//
// TEST(msgpack, pose_st) {
//     vec_t v(1, 1, 1);
//     quaternion_t q(1, 0, 0, 0);
//     pose_st a(v,q), b(v,q), c;
//     ASSERT_EQ(a,b);
//     ASSERT_FALSE(a == c);
//
//     MsgPack<pose_st> buffer;
//     zmq::message_t msg = buffer.pack(a);
//     c = buffer.unpack(msg);
//     ASSERT_EQ(a, c);
//     ASSERT_EQ(a.timestamp, c.timestamp);
// }

TEST(msgpack, imu_st) {
    vec_t v(0.000001,1000,-1);
    imu_st a(v,v,v);
    msg_st<imu_st>(a);
}

// TEST(msgpack, lidar_st) {
//     lidar_st a, b, c;
//
//     for (int i=0; i<5; i++) a.data.push_back(pt_t(i*50, i*2.1));
//     // ASSERT_EQ(a,b);
//     ASSERT_FALSE(a == c);
//
//     MsgPack<lidar_st> buffer;
//     zmq::message_t msg = buffer.pack(a);
//     c = buffer.unpack(msg);
//     ASSERT_EQ(a, c);
//     ASSERT_EQ(a.timestamp,c.timestamp);
// }

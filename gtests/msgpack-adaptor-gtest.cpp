#include <gtest/gtest.h> // googletest header file
#include <gecko/gecko.hpp>
#include <gecko/msgpack/msgs.hpp>
// #include "gecko/msgpack/msgpack_pub_sub.hpp"
#include <string>

using namespace std;

TEST(dummy, simple) {
    ASSERT_TRUE(true);
}


TEST(msgpack, msg_adaptor_uds) {
    gecko::init();

    string uds = zmqUDS("/tmp/0");

    vec_t a(1,-2,3.3);

    Publisher p;
    p.bind(uds);
    // mpPublisher<vec_t> pub(p);
    // pub.publish(a);

    Subscriber s;
    s.connect(uds);
    // mpSubscriber<vec_t> sub(s);
    // vec_t b = sub.recv_nb();

    // we always loose the first message due to subscription time
    // vec_t b;
    // bool ok = false;
    while (1){
        zmq::message_t mm = a.pack();
        p.publish(mm);
        gecko::msleep(100);
        zmq::message_t msg = s.recv_nb();
        if (msg.size() > 0){
            vec_t b(msg);
            ASSERT_TRUE(a == b);
            break;
        }
        // cout << ans << endl;
    }

    // a.print();
    // b.print();

    // ASSERT_TRUE(a == b);
}
//
// TEST(msgpack, msg_adaptor_tcp) {
//     gecko::init();
//     vec_t a(1,-2,3.3);
//
//     Publisher *p = gecko::pubBindTCP("dalek", "test");
//     if (p == nullptr) ASSERT_TRUE(false) << "pubBindTCP failed";
//     mpPublisher<vec_t> pub(p);
//
//     Subscriber *s = gecko::subConnectTCP("dalek", "test");
//     if (s == nullptr) ASSERT_TRUE(false) << "subConnectTCP failed";
//     mpSubscriber<vec_t> sub(s);
//     // vec_t b = sub.recv_nb();
//
//     // we always loose the first message due to subscription time
//     vec_t b;
//     bool ok = false;
//     while (!ok){
//         pub.publish(a);
//         gecko::msleep(100);
//         ok = sub.recv_nb(b);
//         // cout << ans << endl;
//     }
//
//     // a.print();
//     // b.print();
//
//     ASSERT_TRUE(a == b);
// }

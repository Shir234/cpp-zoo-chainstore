#ifndef ZOOKEEPERSTOURGUIDE_H
#define ZOOKEEPERSTOURGUIDE_H

#include "ZooKeeper.h"
#include "TourGuide.h"

class ZooKeepersTourGuide : public ZooKeeper, public TourGuide {
public:
    ZooKeepersTourGuide(const char*& name, int age, int maxEnclosures, int maxLanguages);
    ZooKeepersTourGuide(const ZooKeepersTourGuide& other) = delete;
   // ZooKeepersTourGuide(ZooKeepersTourGuide&& other);
    virtual ~ZooKeepersTourGuide();

    ZooKeepersTourGuide& operator=(const ZooKeepersTourGuide& other) = delete;

    bool prepareTour();
    void educateVisitors() const;
    void speak() const override;


};

#endif

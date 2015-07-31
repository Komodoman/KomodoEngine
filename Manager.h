/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Manager base class, Created by Kyle the Komodoman on 7/29/2015.
*/


#ifndef KOMODO_MANAGER_H
#define KOMODO_MANAGER_H

class Manager {

protected:
    bool is_started;    // True if startUp() is successful

public:
    virtual ~Manager() { }

    Manager() { }

// Start up the Manager
    // Return 0 for OK, else -1
    virtual int startUp() { };

    // Shut down the Manager
    virtual void shutDown() { };

    // Return status of is_started
    bool isStarted() { };
};

#endif //KOMODO_MANAGER_H

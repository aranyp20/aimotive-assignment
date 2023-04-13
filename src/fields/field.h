#pragma once

#include <limits>
#include <unordered_map>

class field
{
protected:
    enum neighbor
    {
        TOP = 0,
        RIGHT = 1,
        BOTTOM = 2,
        LEFT = 3
    };

    virtual void step_to_neighbors(unsigned int jump_length = 1);

    void attempt_value_change(unsigned int distance_to_here);

    void set_shortest_to_here(unsigned int);

private:
    std::unordered_map<neighbor, neighbor> neighbor_opposite{{BOTTOM, TOP}, {TOP, BOTTOM}, {RIGHT, LEFT}, {LEFT, RIGHT}};

    unsigned int shortest_to_here = std::numeric_limits<unsigned int>::max();

    std::unordered_map<neighbor, field &> neighbors;

public:
    virtual void enter(unsigned int distance_to_here, const neighbor from) = 0;

    /* Only return the distance to this node in target nodes, otherwise 0. */
    virtual unsigned int collect_result() const;
};
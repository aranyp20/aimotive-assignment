#pragma once

#include <limits>
#include <unordered_map>

#define UNTOUCHED std::numeric_limits<unsigned int>::max()

class field
{
public:
    enum neighbor
    {
        /* Do NOT change the order! */
        RIGHT = 0,
        TOP = 1,
        LEFT = 2,
        BOTTOM = 3
    };

    virtual void enter(unsigned int distance_to_here, const neighbor from) = 0;
    /* Only return the distance to this node in target nodes, otherwise 0. */
    virtual unsigned int collect_result() const;
    void set_neighbor(const neighbor which, field *to_what);

protected:
    void step_to_neighbors(unsigned int jump_length = 1);
    bool attempt_value_change(unsigned int distance_to_here);
    unsigned int get_shortest_to_here() const;

private:
    static std::unordered_map<neighbor, neighbor> neighbor_opposite;
    unsigned int shortest_to_here = UNTOUCHED;
    std::unordered_map<neighbor, field *> neighbors;
};
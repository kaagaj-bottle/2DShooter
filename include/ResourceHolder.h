#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED
#include <iostream>
#include <memory>
#include "Window.hpp"
#include "System.hpp"
#include "Graphics.hpp"
#include <cassert>
#include <string>


template <class Resource>
class ResourceHolder
{
private:
    std::unique_ptr mResource;
public:
    void load(const std::string& filename);
    Resource& get();
    const Resource& get() const;

};

#include "ResourceHolder.inl"

#endif // RESOURCEHOLDER_H_INCLUDED

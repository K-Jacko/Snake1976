#pragma once


class ILayer{
protected:
    ILayer() = default;
public:
    virtual void Init(){}
    virtual void Update(){}
    virtual void Draw(){}
    virtual void Reset(){}
};
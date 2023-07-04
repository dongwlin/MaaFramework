#pragma once

#include "Common/MaaConf.h"

#include <string_view>

#include <meojson/json.hpp>

#include "Instance/InstanceInternalAPI.hpp"

MAA_TASK_NS_BEGIN

class TaskBase
{
public:
    TaskBase(InstanceInternalAPI* inst, std::string_view task_name) : inst_(inst), task_name_(task_name) {}
    virtual ~TaskBase() = default;

    virtual bool run() = 0;
    virtual bool set_param(const json::value& param) = 0;

    virtual std::string_view type() const = 0;

protected:
    MAA_RES_NS::ResourceMgr* resource() { return inst_->resource(); }
    MAA_CTRL_NS::ControllerMgr* controller() { return inst_->controller(); }
    InstanceStatus* status() { return inst_->status(); }

    std::string_view task_name_;

private:
    InstanceInternalAPI* inst_ = nullptr;
};

MAA_TASK_NS_END

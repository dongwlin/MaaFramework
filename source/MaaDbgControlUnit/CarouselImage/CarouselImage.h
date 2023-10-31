#pragma once

#include "ControlUnit/DbgControlUnitAPI.h"

#include <filesystem>

#include <meojson/json.hpp>

MAA_DBG_CTRL_UNIT_NS_BEGIN

class CarouselImage : public ControllerAPI
{
public:
    CarouselImage(std::filesystem::path path) : path_(std::move(path)) {}
    virtual ~CarouselImage() = default;

public: // from ControllerAPI
    virtual std::string uuid() const override;
    virtual cv::Size resolution() const override;

    virtual bool connect() override;

    virtual bool start_app(const std::string& intent) override;
    virtual bool stop_app(const std::string& intent) override;

    virtual bool click(int x, int y) override;
    virtual bool swipe(int x1, int y1, int x2, int y2, int duration);

    virtual bool touch_down(int contact, int x, int y, int pressure);
    virtual bool touch_move(int contact, int x, int y, int pressure);
    virtual bool touch_up(int contact) override;

    virtual bool press_key(int key) override;

    virtual std::optional<cv::Mat> screencap() override;

private:
    std::filesystem::path path_;
    std::vector<cv::Mat> images_;
    size_t image_index_ = 0;
    cv::Size resolution_ {};
};

MAA_DBG_CTRL_UNIT_NS_END
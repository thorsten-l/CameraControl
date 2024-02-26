#include <CameraControl/impl/CameraBtControlImpl.hpp>
#include <CameraControl/impl/CameraCcApiControlImpl.hpp>
#include <CameraControl/impl/CameraPtpControlImpl.hpp>

std::shared_ptr<CameraControl> cameraControl = nullptr;

std::shared_ptr<CameraControl> CameraControl::getInstance(
    CameraControlType type)
{
  static std::shared_ptr<CameraControl> apiInstance;

  switch (type)
  {
  case CameraControlType::CCAPI:
    apiInstance = std::make_shared<CameraCcApiControl>();
    break;

  case CameraControlType::PTP:
    apiInstance = std::make_shared<CameraPtpControl>();
    break;

  case CameraControlType::BT:
    apiInstance = std::make_shared<CameraBtControl>();
    break;

  default:
    apiInstance = nullptr;
  }

  return apiInstance;
}

#pragma once

#include "winrt/Microsoft.ReactNative.h"
#include "NativeModules.h"
#include "BlurhashView.h"

namespace winrt::Blurhash::implementation
{
    class BlurhashViewManager : public winrt::implements<
        BlurhashViewManager,
        winrt::Microsoft::ReactNative::IViewManager,
        winrt::Microsoft::ReactNative::IViewManagerWithNativeProperties>
    {
    public:
        BlurhashViewManager() = default;

        // IViewManager
        winrt::hstring Name() noexcept;

        winrt::Windows::UI::Xaml::FrameworkElement CreateView() noexcept;

        // IViewManagerWithNativeProperties
        winrt::Windows::Foundation::Collections::
            IMapView<winrt::hstring, winrt::Microsoft::ReactNative::ViewManagerPropertyType>
            NativeProps() noexcept;

        void UpdateProperties(
            winrt::Windows::UI::Xaml::FrameworkElement const& view,
            winrt::Microsoft::ReactNative::IJSValueReader const& propertyMapReader) noexcept;

    private:
        winrt::Blurhash::implementation::BlurhashView _blurhashView { nullptr };
        winrt::Microsoft::ReactNative::IReactContext _reactContext{ nullptr };
    };
}

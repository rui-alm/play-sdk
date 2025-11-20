#pragma once

#include <memory>
#include <pd_api.h>
#include <pd_api/pd_api_sys.h>

#include "graphics/types.h"
#include "system/graphics.h"

namespace ksdk::playdate {

    class graphics : public ksdk::system_graphics
    {
    public:
        graphics(const playdate_graphics& pd_graphics);
        virtual ~graphics();

        // Fonts and text
        virtual int draw_text(const std::string& text, int x, int y) override;
        virtual int set_font(const std::string& path) override;
        virtual int get_font_height(const std::string &path, uint8_t& font_height) const override;
        virtual int get_text_width(const std::string& text) const override;
        virtual int get_text_width(const char* const text, const size_t size) const override;
        // Geometry
        virtual int draw_rect(int x, int y, int width, int height) override;
        // Bitmaps
        virtual ksdk::bitmap* load_bitmap(const std::string& path) override;
        virtual void free_bitmap(ksdk::bitmap* bitmap) override;
        virtual void draw_bitmap(const ksdk::bitmap& bitmap, int x, int y) override;
        virtual void get_bitmap_data(ksdk::bitmap* bitmap, int* width, int* height, int* rowbytes, uint8_t** mask, uint8_t** data) override;
        // Bitmap tables
        virtual std::unique_ptr<ksdk::bitmap_table> new_bitmap_table(const std::string& path, int count, int width, int height) override;
        // Video
        virtual void set_draw_offset(int x, int y) override;
        // Misc
        virtual int clear() override;
        virtual ksdk::bitmap* get_framebuffer() override;

        // Unimplemented
        void push_context(ksdk::bitmap* target);
        void pop_context();
        void set_stencil(ksdk::bitmap* stencil);
        // void set_draw_mode(ksdk::bitmap_draw_mode mode);
        void set_clip_rect(int x, int y, int width, int height);
        void set_screen_clip_rect(int x, int y, int width, int height);
        void clear_clip_rect();
        // void set_line_cap_stype(ksdk::line_cap_style end_cap_style);
        void set_text_tracking(int tracking);
        int get_text_tracking();
    private:
        playdate_graphics& pd_graphics;
        std::unique_ptr<LCDFont, void(*)(LCDFont*)> selected_font;

        static void free_font(LCDFont* font);
    };
}

#include "playdate/graphics/pd_bitmap_table.h"

#include <pd_api.h>

#include "graphics/bitmap_table.h"
#include "graphics/types.h"

// using namespace ksdk::playdate;

// bitmap_table::bitmap_table(playdate_graphics& graphics,
//     const std::string& path, const size_t count,
//     const size_t width, const size_t height)
//     : ksdk::bitmap_table(), graphics(graphics),
//     table(graphics.newBitmapTable(count, width, height))
// {
//     const char* err;
//     graphics.loadIntoBitmapTable(path.c_str(), table, &err);
// }

// bitmap_table::~bitmap_table()
// {
//     graphics.freeBitmapTable(table);
// }

// ksdk::bitmap& bitmap_table::get(int idx) const
// {
//     LCDBitmap* pd_bitmap = graphics.getTableBitmap(table, idx);
//     return *pd_bitmap;
// }

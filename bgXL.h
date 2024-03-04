
//{{BLOCK(bgXL)

//======================================================================
//
//	bgXL, 2304x256@4, 
//	+ palette 256 entries, not compressed
//	+ 135 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 288x32 
//	Total size: 512 + 4320 + 18432 = 23264
//
//	Time-stamp: 2024-01-19, 19:47:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BGXL_H
#define GRIT_BGXL_H

#define bgXLTilesLen 4320
extern const unsigned short bgXLTiles[2160];

#define bgXLMapLen 18432
extern const unsigned short bgXLMap[9216];

#define bgXLPalLen 512
extern const unsigned short bgXLPal[256];

#endif // GRIT_BGXL_H

//}}BLOCK(bgXL)

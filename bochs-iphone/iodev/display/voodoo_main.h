/////////////////////////////////////////////////////////////////////////
// $Id: voodoo_main.h 12101 2014-01-07 22:32:22Z vruppert $
/////////////////////////////////////////////////////////////////////////
/*
 *  Portion of this software comes with the following license
 */

/***************************************************************************

    Copyright Aaron Giles
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in
          the documentation and/or other materials provided with the
          distribution.
        * Neither the name 'MAME' nor the names of its contributors may be
          used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY AARON GILES ''AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL AARON GILES BE LIABLE FOR ANY DIRECT,
    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
    IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

***************************************************************************/

#ifndef VOODOO_MAIN_H
#define VOODOO_MAIN_H

/* enumeration specifying which model of Voodoo we are emulating */
enum
{
  VOODOO_1,
  VOODOO_2,
  VOODOO_BANSHEE,
  VOODOO_3,
  MAX_VOODOO_TYPES
};


#define STD_VOODOO_1_CLOCK       50000000.0
#define STD_VOODOO_2_CLOCK       90000000.0
#define STD_VOODOO_BANSHEE_CLOCK 90000000.0
#define STD_VOODOO_3_CLOCK      132000000.0


/***************************************************************************
    TYPE DEFINITIONS
***************************************************************************

typedef void (*voodoo_vblank_func)(running_device *device, int state);
typedef void (*voodoo_stall_func)(running_device *device, int state);

*/
typedef struct _voodoo_config voodoo_config;
struct _voodoo_config
{
  int         type;
  Bit8u       fbmem;
  Bit8u       tmumem0;
  Bit8u       tmumem1;
  const char *    screen;
  const char *    cputag;
//  voodoo_vblank_func  vblank;
//  voodoo_stall_func stall;
};



/***************************************************************************
    DEVICE CONFIGURATION MACROS
***************************************************************************

#define MDRV_3DFX_VOODOO_ADD(_tag, _type, _clock, _fbmem, _screen) \
  MDRV_DEVICE_ADD(_tag, VOODOO_GRAPHICS, _clock) \
  MDRV_DEVICE_CONFIG_DATA32(voodoo_config, type, _type) \
  MDRV_DEVICE_CONFIG_DATA32(voodoo_config, fbmem, _fbmem) \
  MDRV_DEVICE_CONFIG_DATAPTR(voodoo_config, screen, _screen)

#define MDRV_3DFX_VOODOO_1_ADD(_tag, _clock, _fbmem, _screen) \
  MDRV_3DFX_VOODOO_ADD(_tag, VOODOO_1, _clock, _fbmem, _screen)

#define MDRV_3DFX_VOODOO_2_ADD(_tag, _clock, _fbmem, _screen) \
  MDRV_3DFX_VOODOO_ADD(_tag, VOODOO_2, _clock, _fbmem, _screen)

#define MDRV_3DFX_VOODOO_BANSHEE_ADD(_tag, _clock, _fbmem, _screen) \
  MDRV_3DFX_VOODOO_ADD(_tag, VOODOO_BANSHEE, _clock, _fbmem, _screen)

#define MDRV_3DFX_VOODOO_3_ADD(_tag, _clock, _fbmem, _screen) \
  MDRV_3DFX_VOODOO_ADD(_tag, VOODOO_3, _clock, _fbmem, _screen)

#define MDRV_3DFX_VOODOO_TMU_MEMORY(_tmu, _tmumem) \
  MDRV_DEVICE_CONFIG_DATA32(voodoo_config, tmumem##_tmu, _tmumem)

#define MDRV_3DFX_VOODOO_VBLANK(_vblank) \
  MDRV_DEVICE_CONFIG_DATAPTR(voodoo_config, vblank, _vblank)

#define MDRV_3DFX_VOODOO_STALL(_stall) \
  MDRV_DEVICE_CONFIG_DATAPTR(voodoo_config, stall, _stall)

#define MDRV_3DFX_VOODOO_CPU(_cputag) \
  MDRV_DEVICE_CONFIG_DATAPTR(voodoo_config, cputag, _cputag)

#define MDRV_3DFX_VOODOO_MODIFY(_tag) \
  MDRV_DEVICE_MODIFY(_tag)
*/


/***************************************************************************
    FUNCTION PROTOTYPES
***************************************************************************

int voodoo_update(running_device *device, bitmap_t *bitmap, const rectangle *cliprect);
int voodoo_get_type(running_device *device);
int voodoo_is_stalled(running_device *device);
void voodoo_set_init_enable(running_device *device, UINT32 newval);

READ32_DEVICE_HANDLER( voodoo_r );
WRITE32_DEVICE_HANDLER( voodoo_w );

READ32_DEVICE_HANDLER( banshee_r );
WRITE32_DEVICE_HANDLER( banshee_w );
READ32_DEVICE_HANDLER( banshee_fb_r );
WRITE32_DEVICE_HANDLER( banshee_fb_w );
READ32_DEVICE_HANDLER( banshee_io_r );
WRITE32_DEVICE_HANDLER( banshee_io_w );
READ32_DEVICE_HANDLER( banshee_rom_r );

*/
#define VOODOO_MEM 0x60000000
#define VOODOO_REG_PAGES 1024
#define VOODOO_LFB_PAGES 1024
#define VOODOO_TEX_PAGES 2048
#define VOODOO_PAGES (VOODOO_REG_PAGES+VOODOO_LFB_PAGES+VOODOO_TEX_PAGES)

#define Voodoo_UpdateScreenStart() theVoodooDevice->update_screen_start()
#define Voodoo_Output_Enable(x)    theVoodooDevice->output_enable(x)
#define Voodoo_get_retrace()       theVoodooDevice->get_retrace()
#define Voodoo_update_timing()       theVoodooDevice->update_timing()

#endif

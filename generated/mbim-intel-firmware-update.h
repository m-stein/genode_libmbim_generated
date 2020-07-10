
/* GENERATED CODE... DO NOT EDIT */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 - 2018 Aleksander Morgado <aleksander@aleksander.es>
 */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "mbim-message.h"
#include "mbim-device.h"
#include "mbim-enums.h"

#ifndef __LIBMBIM_GLIB_MBIM_INTEL_FIRMWARE_UPDATE__
#define __LIBMBIM_GLIB_MBIM_INTEL_FIRMWARE_UPDATE__

G_BEGIN_DECLS

/*****************************************************************************/
/* Message (Set): MBIM Message Intel Firmware Update Modem Reboot */

/**
 * mbim_message_intel_firmware_update_modem_reboot_set_new:
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Modem Reboot' set command in the 'Intel Firmware Update' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.16
 */
MbimMessage *mbim_message_intel_firmware_update_modem_reboot_set_new (
    GError **error);

/*****************************************************************************/
/* Service helper for printable fields */

#if defined (LIBMBIM_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *
__mbim_message_intel_firmware_update_get_printable_fields (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error);

#endif

G_END_DECLS

#endif /* __LIBMBIM_GLIB_MBIM_INTEL_FIRMWARE_UPDATE__ */

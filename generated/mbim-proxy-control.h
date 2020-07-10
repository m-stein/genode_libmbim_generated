
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

#ifndef __LIBMBIM_GLIB_MBIM_PROXY_CONTROL__
#define __LIBMBIM_GLIB_MBIM_PROXY_CONTROL__

G_BEGIN_DECLS

/*****************************************************************************/
/* Message (Set): MBIM Message Proxy Control Configuration */

/**
 * mbim_message_proxy_control_configuration_set_new:
 * @device_path: (in): the 'DevicePath' field, given as a string.
 * @timeout: (in): the 'Timeout' field, given as a #guint32.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Configuration' set command in the 'Proxy Control' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.10
 */
MbimMessage *mbim_message_proxy_control_configuration_set_new (
    const gchar *device_path,
    guint32 timeout,
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Proxy Control Configuration */

/**
 * mbim_message_proxy_control_configuration_response_parse:
 * @message: the #MbimMessage.
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Configuration' response command in the 'Proxy Control' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.10
 */
gboolean mbim_message_proxy_control_configuration_response_parse (
    const MbimMessage *message,
    GError **error);

/*****************************************************************************/
/* Service helper for printable fields */

#if defined (LIBMBIM_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *
__mbim_message_proxy_control_get_printable_fields (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error);

#endif

G_END_DECLS

#endif /* __LIBMBIM_GLIB_MBIM_PROXY_CONTROL__ */

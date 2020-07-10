
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


#include <string.h>

#include "mbim-proxy-control.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Message (Set): MBIM Message Proxy Control Configuration */

MbimMessage *
mbim_message_proxy_control_configuration_set_new (
    const gchar *device_path,
    guint32 timeout,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_PROXY_CONTROL,
                                                 MBIM_CID_PROXY_CONTROL_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_string (builder, device_path);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, timeout);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_proxy_control_configuration_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  DevicePath = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Timeout = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Proxy Control Configuration */

gboolean
mbim_message_proxy_control_configuration_response_parse (
    const MbimMessage *message,
    GError **error)
{

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    return TRUE;
}

static gchar *
mbim_message_proxy_control_configuration_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

typedef struct {
  gchar * (* query_cb)        (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* set_cb)          (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* response_cb)     (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* notification_cb) (const MbimMessage *message, const gchar *line_prefix, GError **error);
} GetPrintableCallbacks;

static const GetPrintableCallbacks get_printable_callbacks[] = {
    [MBIM_CID_PROXY_CONTROL_CONFIGURATION] = {
        .set_cb = mbim_message_proxy_control_configuration_set_get_printable,
        .response_cb = mbim_message_proxy_control_configuration_response_get_printable,
    },
};

gchar *
__mbim_message_proxy_control_get_printable_fields (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    guint32 cid;

    switch (mbim_message_get_message_type (message)) {
        case MBIM_MESSAGE_TYPE_COMMAND: {
            cid = mbim_message_command_get_cid (message);
            if (cid < G_N_ELEMENTS (get_printable_callbacks)) {
                switch (mbim_message_command_get_command_type (message)) {
                    case MBIM_MESSAGE_COMMAND_TYPE_QUERY:
                        if (get_printable_callbacks[cid].query_cb)
                            return get_printable_callbacks[cid].query_cb (message, line_prefix, error);
                        break;
                    case MBIM_MESSAGE_COMMAND_TYPE_SET:
                        if (get_printable_callbacks[cid].set_cb)
                            return get_printable_callbacks[cid].set_cb (message, line_prefix, error);
                        break;
                    case MBIM_MESSAGE_COMMAND_TYPE_UNKNOWN:
                    default:
                        g_set_error (error,
                                     MBIM_CORE_ERROR,
                                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                                     "Invalid command type");
                        return NULL;
                }
            }
            break;
        }

        case MBIM_MESSAGE_TYPE_COMMAND_DONE:
            cid = mbim_message_command_done_get_cid (message);
            if (cid < G_N_ELEMENTS (get_printable_callbacks)) {
                if (get_printable_callbacks[cid].response_cb)
                    return get_printable_callbacks[cid].response_cb (message, line_prefix, error);
            }
            break;

        case MBIM_MESSAGE_TYPE_INDICATE_STATUS:
            cid = mbim_message_indicate_status_get_cid (message);
            if (cid < G_N_ELEMENTS (get_printable_callbacks)) {
                if (get_printable_callbacks[cid].notification_cb)
                    return get_printable_callbacks[cid].notification_cb (message, line_prefix, error);
            }
            break;

        case MBIM_MESSAGE_TYPE_OPEN: 
        case MBIM_MESSAGE_TYPE_CLOSE: 
        case MBIM_MESSAGE_TYPE_INVALID: 
        case MBIM_MESSAGE_TYPE_HOST_ERROR: 
        case MBIM_MESSAGE_TYPE_OPEN_DONE: 
        case MBIM_MESSAGE_TYPE_CLOSE_DONE: 
        case MBIM_MESSAGE_TYPE_FUNCTION_ERROR: 
        default:
            g_set_error (error,
                         MBIM_CORE_ERROR,
                         MBIM_CORE_ERROR_INVALID_MESSAGE,
                         "No contents expected in this message type");
            return NULL;
    }

    g_set_error (error,
                 MBIM_CORE_ERROR,
                 MBIM_CORE_ERROR_INVALID_MESSAGE,
                 "Unknown contents");
    return NULL;
}

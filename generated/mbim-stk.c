
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

#include "mbim-stk.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Message (Query): MBIM Message STK Pac */

MbimMessage *
mbim_message_stk_pac_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_STK,
                                                 MBIM_CID_STK_PAC,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_stk_pac_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message STK Pac */

MbimMessage *
mbim_message_stk_pac_set_new (
    const guint8 *pac_host_control,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_STK,
                                                 MBIM_CID_STK_PAC,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, pac_host_control, 32);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_stk_pac_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PacHostControl = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 32, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 32;
        offset += 32;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
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
/* Message (Response): MBIM Message STK Pac */

gboolean
mbim_message_stk_pac_response_parse (
    const MbimMessage *message,
    const guint8 **out_pac_support,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'PacSupport' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 256, &tmp, NULL, error))
            goto out;
        if (out_pac_support != NULL)
            *out_pac_support = tmp;
        offset += 256;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_stk_pac_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PacSupport = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 256, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 256;
        offset += 256;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
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
/* Message (Notification): MBIM Message STK Pac */

gboolean
mbim_message_stk_pac_notification_parse (
    const MbimMessage *message,
    MbimStkPacType *out_pac_type,
    guint32 *out_data_buffer_size,
    const guint8 **out_data_buffer,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_INDICATE_STATUS) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a notification");
        return FALSE;
    }

    if (!mbim_message_indicate_status_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'PacType' variable */
    {
        if (out_pac_type != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_pac_type = (MbimStkPacType)aux;
        }
        offset += 4;
    }

    /* Read the 'DataBuffer' variable */
    {
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 0, &tmp, &tmpsize, error))
            goto out;
        if (out_data_buffer != NULL)
            *out_data_buffer = tmp;
        if (out_data_buffer_size != NULL)
            *out_data_buffer_size = tmpsize;
        offset += tmpsize;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_stk_pac_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PacType = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_STK_PAC_TYPE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_stk_pac_type_get_string ((MbimStkPacType)tmp));
#elif defined __MBIM_STK_PAC_TYPE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_stk_pac_type_build_string_from_mask ((MbimStkPacType)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  DataBuffer = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 0, &tmp, &tmpsize, &inner_error))
            goto out;
        offset += tmpsize;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
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
/* Message (Set): MBIM Message STK Terminal Response */

MbimMessage *
mbim_message_stk_terminal_response_set_new (
    const guint32 response_size,
    const guint8 *response,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_STK,
                                                 MBIM_CID_STK_TERMINAL_RESPONSE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, TRUE, TRUE, response, response_size);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_stk_terminal_response_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Response = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, TRUE, 0, &tmp, &tmpsize, &inner_error))
            goto out;
        offset += 4;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
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
/* Message (Response): MBIM Message STK Terminal Response */

gboolean
mbim_message_stk_terminal_response_response_parse (
    const MbimMessage *message,
    guint32 *out_result_data_size,
    const guint8 **out_result_data,
    guint32 *out_status_words,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'ResultData' variable */
    {
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, TRUE, TRUE, 0, &tmp, &tmpsize, error))
            goto out;
        if (out_result_data != NULL)
            *out_result_data = tmp;
        if (out_result_data_size != NULL)
            *out_result_data_size = tmpsize;
        offset += 8;
    }

    /* Read the 'StatusWords' variable */
    {
        if ((out_status_words != NULL) && !_mbim_message_read_guint32 (message, offset, out_status_words, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_stk_terminal_response_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ResultData = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, TRUE, TRUE, 0, &tmp, &tmpsize, &inner_error))
            goto out;
        offset += 8;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  StatusWords = ", line_prefix);
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
/* Message (Query): MBIM Message STK Envelope */

MbimMessage *
mbim_message_stk_envelope_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_STK,
                                                 MBIM_CID_STK_ENVELOPE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_stk_envelope_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message STK Envelope */

MbimMessage *
mbim_message_stk_envelope_set_new (
    const guint32 data_size,
    const guint8 *data,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_STK,
                                                 MBIM_CID_STK_ENVELOPE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, data, data_size);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_stk_envelope_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Data = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 0, &tmp, &tmpsize, &inner_error))
            goto out;
        offset += tmpsize;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
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
/* Message (Response): MBIM Message STK Envelope */

gboolean
mbim_message_stk_envelope_response_parse (
    const MbimMessage *message,
    const guint8 **out_envelope_support,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;

    if (mbim_message_get_message_type (message) != MBIM_MESSAGE_TYPE_COMMAND_DONE) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message is not a response");
        return FALSE;
    }

    if (!mbim_message_command_done_get_raw_information_buffer (message, NULL)) {
        g_set_error (error,
                     MBIM_CORE_ERROR,
                     MBIM_CORE_ERROR_INVALID_MESSAGE,
                     "Message does not have information buffer");
        return FALSE;
    }

    /* Read the 'EnvelopeSupport' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 32, &tmp, NULL, error))
            goto out;
        if (out_envelope_support != NULL)
            *out_envelope_support = tmp;
        offset += 32;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_stk_envelope_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  EnvelopeSupport = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 32, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 32;
        offset += 32;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

 out:
    if (inner_error) {
        g_string_append_printf (str, "n/a: %s", inner_error->message);
        g_clear_error (&inner_error);
    }

    return g_string_free (str, FALSE);
}

typedef struct {
  gchar * (* query_cb)        (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* set_cb)          (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* response_cb)     (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* notification_cb) (const MbimMessage *message, const gchar *line_prefix, GError **error);
} GetPrintableCallbacks;

static const GetPrintableCallbacks get_printable_callbacks[] = {
    [MBIM_CID_STK_PAC] = {
        .query_cb = mbim_message_stk_pac_query_get_printable,
        .set_cb = mbim_message_stk_pac_set_get_printable,
        .response_cb = mbim_message_stk_pac_response_get_printable,
        .notification_cb = mbim_message_stk_pac_notification_get_printable,
    },
    [MBIM_CID_STK_TERMINAL_RESPONSE] = {
        .set_cb = mbim_message_stk_terminal_response_set_get_printable,
        .response_cb = mbim_message_stk_terminal_response_response_get_printable,
    },
    [MBIM_CID_STK_ENVELOPE] = {
        .query_cb = mbim_message_stk_envelope_query_get_printable,
        .set_cb = mbim_message_stk_envelope_set_get_printable,
        .response_cb = mbim_message_stk_envelope_response_get_printable,
    },
};

gchar *
__mbim_message_stk_get_printable_fields (
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

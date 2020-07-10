
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

#include "mbim-auth.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Message (Query): MBIM Message Auth Aka */

MbimMessage *
mbim_message_auth_aka_query_new (
    const guint8 *rand,
    const guint8 *autn,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_AUTH,
                                                 MBIM_CID_AUTH_AKA,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, rand, 16);
    }
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, autn, 16);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_auth_aka_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Rand = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Autn = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
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
/* Message (Response): MBIM Message Auth Aka */

gboolean
mbim_message_auth_aka_response_parse (
    const MbimMessage *message,
    const guint8 **out_res,
    guint32 *out_res_len,
    const guint8 **out_integrating_key,
    const guint8 **out_ciphering_key,
    const guint8 **out_auts,
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

    /* Read the 'Res' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, error))
            goto out;
        if (out_res != NULL)
            *out_res = tmp;
        offset += 16;
    }

    /* Read the 'ResLen' variable */
    {
        if ((out_res_len != NULL) && !_mbim_message_read_guint32 (message, offset, out_res_len, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IntegratingKey' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, error))
            goto out;
        if (out_integrating_key != NULL)
            *out_integrating_key = tmp;
        offset += 16;
    }

    /* Read the 'CipheringKey' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, error))
            goto out;
        if (out_ciphering_key != NULL)
            *out_ciphering_key = tmp;
        offset += 16;
    }

    /* Read the 'Auts' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 14, &tmp, NULL, error))
            goto out;
        if (out_auts != NULL)
            *out_auts = tmp;
        offset += 14;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_auth_aka_response_get_printable (
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

    g_string_append_printf (str, "%s  Res = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ResLen = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IntegratingKey = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CipheringKey = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Auts = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 14, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 14;
        offset += 14;
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
/* Message (Query): MBIM Message Auth Akap */

MbimMessage *
mbim_message_auth_akap_query_new (
    const guint8 *rand,
    const guint8 *autn,
    const gchar *network_name,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_AUTH,
                                                 MBIM_CID_AUTH_AKAP,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, rand, 16);
    }
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, autn, 16);
    }
    {
        _mbim_message_command_builder_append_string (builder, network_name);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_auth_akap_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Rand = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Autn = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NetworkName = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
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
/* Message (Response): MBIM Message Auth Akap */

gboolean
mbim_message_auth_akap_response_parse (
    const MbimMessage *message,
    const guint8 **out_res,
    guint32 *out_res_len,
    const guint8 **out_integrating_key,
    const guint8 **out_ciphering_key,
    const guint8 **out_auts,
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

    /* Read the 'Res' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, error))
            goto out;
        if (out_res != NULL)
            *out_res = tmp;
        offset += 16;
    }

    /* Read the 'ResLen' variable */
    {
        if ((out_res_len != NULL) && !_mbim_message_read_guint32 (message, offset, out_res_len, error))
            goto out;
        offset += 4;
    }

    /* Read the 'IntegratingKey' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, error))
            goto out;
        if (out_integrating_key != NULL)
            *out_integrating_key = tmp;
        offset += 16;
    }

    /* Read the 'CipheringKey' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, error))
            goto out;
        if (out_ciphering_key != NULL)
            *out_ciphering_key = tmp;
        offset += 16;
    }

    /* Read the 'Auts' variable */
    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 14, &tmp, NULL, error))
            goto out;
        if (out_auts != NULL)
            *out_auts = tmp;
        offset += 14;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_auth_akap_response_get_printable (
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

    g_string_append_printf (str, "%s  Res = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ResLen = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  IntegratingKey = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CipheringKey = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Auts = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 14, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 14;
        offset += 14;
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
/* Message (Query): MBIM Message Auth Sim */

MbimMessage *
mbim_message_auth_sim_query_new (
    const guint8 *rand1,
    const guint8 *rand2,
    const guint8 *rand3,
    guint32 n,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_AUTH,
                                                 MBIM_CID_AUTH_SIM,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, rand1, 16);
    }
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, rand2, 16);
    }
    {
        _mbim_message_command_builder_append_byte_array (builder, FALSE, FALSE, TRUE, rand3, 16);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, n);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_auth_sim_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Rand1 = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Rand2 = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Rand3 = ", line_prefix);
    {
        guint i;
        const guint8 *tmp;
        guint32 tmpsize;

        if (!_mbim_message_read_byte_array (message, 0, offset, FALSE, FALSE, 16, &tmp, NULL, &inner_error))
            goto out;
        tmpsize = 16;
        offset += 16;
        g_string_append (str, "'");
        for (i = 0; i  < tmpsize; i++)
            g_string_append_printf (str, "%02x%s", tmp[i], (i == (tmpsize - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  N = ", line_prefix);
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
/* Message (Response): MBIM Message Auth Sim */

gboolean
mbim_message_auth_sim_response_parse (
    const MbimMessage *message,
    guint32 *out_sres1,
    guint64 *out_kc1,
    guint32 *out_sres2,
    guint64 *out_kc2,
    guint32 *out_sres3,
    guint64 *out_kc3,
    guint32 *out_n,
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

    /* Read the 'Sres1' variable */
    {
        if ((out_sres1 != NULL) && !_mbim_message_read_guint32 (message, offset, out_sres1, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Kc1' variable */
    {
        if ((out_kc1 != NULL) && !_mbim_message_read_guint64 (message, offset, out_kc1, error))
            goto out;
        offset += 8;
    }

    /* Read the 'Sres2' variable */
    {
        if ((out_sres2 != NULL) && !_mbim_message_read_guint32 (message, offset, out_sres2, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Kc2' variable */
    {
        if ((out_kc2 != NULL) && !_mbim_message_read_guint64 (message, offset, out_kc2, error))
            goto out;
        offset += 8;
    }

    /* Read the 'Sres3' variable */
    {
        if ((out_sres3 != NULL) && !_mbim_message_read_guint32 (message, offset, out_sres3, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Kc3' variable */
    {
        if ((out_kc3 != NULL) && !_mbim_message_read_guint64 (message, offset, out_kc3, error))
            goto out;
        offset += 8;
    }

    /* Read the 'N' variable */
    {
        if ((out_n != NULL) && !_mbim_message_read_guint32 (message, offset, out_n, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_auth_sim_response_get_printable (
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

    g_string_append_printf (str, "%s  Sres1 = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Kc1 = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Sres2 = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Kc2 = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Sres3 = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Kc3 = ", line_prefix);
    {
        guint64 tmp;

        if (!_mbim_message_read_guint64 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%" G_GUINT64_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  N = ", line_prefix);
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

typedef struct {
  gchar * (* query_cb)        (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* set_cb)          (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* response_cb)     (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* notification_cb) (const MbimMessage *message, const gchar *line_prefix, GError **error);
} GetPrintableCallbacks;

static const GetPrintableCallbacks get_printable_callbacks[] = {
    [MBIM_CID_AUTH_AKA] = {
        .query_cb = mbim_message_auth_aka_query_get_printable,
        .response_cb = mbim_message_auth_aka_response_get_printable,
    },
    [MBIM_CID_AUTH_AKAP] = {
        .query_cb = mbim_message_auth_akap_query_get_printable,
        .response_cb = mbim_message_auth_akap_response_get_printable,
    },
    [MBIM_CID_AUTH_SIM] = {
        .query_cb = mbim_message_auth_sim_query_get_printable,
        .response_cb = mbim_message_auth_sim_response_get_printable,
    },
};

gchar *
__mbim_message_auth_get_printable_fields (
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

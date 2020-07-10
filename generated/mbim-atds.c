
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

#include "mbim-atds.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Struct: MbimAtdsProvider */

static void
_mbim_atds_provider_free (MbimAtdsProvider *var)
{
    if (!var)
        return;

    g_free (var->provider_id);
    g_free (var->provider_name);
    g_free (var);
}

void
mbim_atds_provider_array_free (MbimAtdsProviderArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_atds_provider_free (array[i]);
    g_free (array);
}

static MbimAtdsProvider *
_mbim_message_read_mbim_atds_provider_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimAtdsProvider *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimAtdsProvider, 1);

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->provider_id, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->provider_state, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->provider_name, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->plmn_mode, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->rssi, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->error_rate, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->provider_id);
    g_free (out->provider_name);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_atds_provider_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimAtdsProviderArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimAtdsProviderArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimAtdsProvider *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_atds_provider_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_atds_provider_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_atds_provider_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_atds_provider_struct (
    const MbimAtdsProvider *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->provider_id);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ProviderState = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->provider_state);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ProviderName = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->provider_name);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PlmnMode = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->plmn_mode);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Rssi = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->rssi);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  ErrorRate = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->error_rate);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_atds_provider_struct_new (const MbimAtdsProvider *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_string (builder, value->provider_id);
    _mbim_struct_builder_append_guint32 (builder, value->provider_state);
    _mbim_struct_builder_append_string (builder, value->provider_name);
    _mbim_struct_builder_append_guint32 (builder, value->plmn_mode);
    _mbim_struct_builder_append_guint32 (builder, value->rssi);
    _mbim_struct_builder_append_guint32 (builder, value->error_rate);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_atds_provider_struct (
    MbimStructBuilder *builder,
    const MbimAtdsProvider *value)
{
    GByteArray *raw;

    raw = _mbim_atds_provider_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_atds_provider_struct (
    MbimMessageCommandBuilder *builder,
    const MbimAtdsProvider *value)
{
    _mbim_struct_builder_append_mbim_atds_provider_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_atds_provider_struct_array (
    MbimStructBuilder *builder,
    const MbimAtdsProvider *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_atds_provider_struct_new (values[i]);
            if (!raw_all)
                raw_all = raw;
            else {
                g_byte_array_append (raw_all, raw->data, raw->len);
                g_byte_array_unref (raw);
            }
        }

        if (!raw_all) {
            offset = 0;
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
        } else {
            guint32 offset_offset;

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;
            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);
            /* Add the final array itself */
            g_byte_array_append (builder->variable_buffer, raw_all->data, raw_all->len);
            g_byte_array_unref (raw_all);
        }
    } else {
        for (i = 0; i < n_values; i++) {
            guint32 length;
            guint32 offset_offset;
            GByteArray *raw;

            raw = _mbim_atds_provider_struct_new (values[i]);
            g_assert (raw->len > 0);

            /* Offset of the offset */
            offset_offset = builder->fixed_buffer->len;

            /* Length *not* in LE yet */
            offset = builder->variable_buffer->len;
            /* Add the offset value */
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&offset, sizeof (offset));
            /* Configure the value to get updated */
            g_array_append_val (builder->offsets, offset_offset);

            /* Add the length value */
            length = GUINT32_TO_LE (raw->len);
            g_byte_array_append (builder->fixed_buffer, (guint8 *)&length, sizeof (length));

            /* And finally, the bytearray itself to the variable buffer */
            g_byte_array_append (builder->variable_buffer, (const guint8 *)raw->data, (guint)raw->len);
            g_byte_array_unref (raw);
        }
    }
}

static void
_mbim_message_command_builder_append_mbim_atds_provider_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimAtdsProvider *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_atds_provider_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Message (Query): MBIM Message ATDS Signal */

MbimMessage *
mbim_message_atds_signal_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_ATDS,
                                                 MBIM_CID_ATDS_SIGNAL,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_atds_signal_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message ATDS Signal */

gboolean
mbim_message_atds_signal_response_parse (
    const MbimMessage *message,
    guint32 *out_rssi,
    guint32 *out_error_rate,
    guint32 *out_rscp,
    guint32 *out_ecno,
    guint32 *out_rsrq,
    guint32 *out_rsrp,
    guint32 *out_rssnr,
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

    /* Read the 'Rssi' variable */
    {
        if ((out_rssi != NULL) && !_mbim_message_read_guint32 (message, offset, out_rssi, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ErrorRate' variable */
    {
        if ((out_error_rate != NULL) && !_mbim_message_read_guint32 (message, offset, out_error_rate, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Rscp' variable */
    {
        if ((out_rscp != NULL) && !_mbim_message_read_guint32 (message, offset, out_rscp, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Ecno' variable */
    {
        if ((out_ecno != NULL) && !_mbim_message_read_guint32 (message, offset, out_ecno, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Rsrq' variable */
    {
        if ((out_rsrq != NULL) && !_mbim_message_read_guint32 (message, offset, out_rsrq, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Rsrp' variable */
    {
        if ((out_rsrp != NULL) && !_mbim_message_read_guint32 (message, offset, out_rsrp, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Rssnr' variable */
    {
        if ((out_rssnr != NULL) && !_mbim_message_read_guint32 (message, offset, out_rssnr, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_atds_signal_response_get_printable (
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

    g_string_append_printf (str, "%s  Rssi = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ErrorRate = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Rscp = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Ecno = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Rsrq = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Rsrp = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Rssnr = ", line_prefix);
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
/* Message (Query): MBIM Message ATDS Location */

MbimMessage *
mbim_message_atds_location_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_ATDS,
                                                 MBIM_CID_ATDS_LOCATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_atds_location_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message ATDS Location */

gboolean
mbim_message_atds_location_response_parse (
    const MbimMessage *message,
    guint32 *out_lac,
    guint32 *out_tac,
    guint32 *out_cell_id,
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

    /* Read the 'Lac' variable */
    {
        if ((out_lac != NULL) && !_mbim_message_read_guint32 (message, offset, out_lac, error))
            goto out;
        offset += 4;
    }

    /* Read the 'Tac' variable */
    {
        if ((out_tac != NULL) && !_mbim_message_read_guint32 (message, offset, out_tac, error))
            goto out;
        offset += 4;
    }

    /* Read the 'CellId' variable */
    {
        if ((out_cell_id != NULL) && !_mbim_message_read_guint32 (message, offset, out_cell_id, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_atds_location_response_get_printable (
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

    g_string_append_printf (str, "%s  Lac = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Tac = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CellId = ", line_prefix);
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
/* Message (Query): MBIM Message ATDS Operators */

MbimMessage *
mbim_message_atds_operators_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_ATDS,
                                                 MBIM_CID_ATDS_OPERATORS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_atds_operators_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message ATDS Operators */

gboolean
mbim_message_atds_operators_response_parse (
    const MbimMessage *message,
    guint32 *out_providers_count,
    MbimAtdsProviderArray **out_providers,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _providers_count;
    MbimAtdsProvider **_providers = NULL;

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

    /* Read the 'ProvidersCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, error))
            goto out;
        if (out_providers_count != NULL)
            *out_providers_count = _providers_count;
        offset += 4;
    }

    /* Read the 'Providers' variable */
    {
        if ((out_providers != NULL) && !_mbim_message_read_mbim_atds_provider_struct_array (message, _providers_count, offset, TRUE, &_providers, error))
            goto out;
        offset += (8 * _providers_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_providers != NULL)
            *out_providers = _providers;
    } else {
        mbim_atds_provider_array_free (_providers);
    }

    return success;
}

static gchar *
mbim_message_atds_operators_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _providers_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ProvidersCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_providers_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _providers_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Providers = ", line_prefix);
    {
        g_autoptr(MbimAtdsProviderArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_atds_provider_struct_array (message, _providers_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _providers_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _providers_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_atds_provider_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
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
/* Message (Query): MBIM Message ATDS RAT */

MbimMessage *
mbim_message_atds_rat_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_ATDS,
                                                 MBIM_CID_ATDS_RAT,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_atds_rat_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message ATDS RAT */

MbimMessage *
mbim_message_atds_rat_set_new (
    MbimAtdsRatMode mode,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_ATDS,
                                                 MBIM_CID_ATDS_RAT,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, mode);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_atds_rat_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Mode = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_ATDS_RAT_MODE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_atds_rat_mode_get_string ((MbimAtdsRatMode)tmp));
#elif defined __MBIM_ATDS_RAT_MODE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_atds_rat_mode_build_string_from_mask ((MbimAtdsRatMode)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

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
/* Message (Response): MBIM Message ATDS RAT */

gboolean
mbim_message_atds_rat_response_parse (
    const MbimMessage *message,
    MbimAtdsRatMode *out_mode,
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

    /* Read the 'Mode' variable */
    {
        if (out_mode != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_mode = (MbimAtdsRatMode)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_atds_rat_response_get_printable (
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

    g_string_append_printf (str, "%s  Mode = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_ATDS_RAT_MODE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_atds_rat_mode_get_string ((MbimAtdsRatMode)tmp));
#elif defined __MBIM_ATDS_RAT_MODE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_atds_rat_mode_build_string_from_mask ((MbimAtdsRatMode)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

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
/* Message (Query): MBIM Message ATDS Register State */

MbimMessage *
mbim_message_atds_register_state_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_ATDS,
                                                 MBIM_CID_ATDS_REGISTER_STATE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_atds_register_state_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message ATDS Register State */

gboolean
mbim_message_atds_register_state_response_parse (
    const MbimMessage *message,
    MbimNwError *out_nw_error,
    MbimRegisterState *out_register_state,
    MbimRegisterMode *out_register_mode,
    MbimDataClass *out_available_data_classes,
    MbimCellularClass *out_current_cellular_class,
    gchar **out_provider_id,
    gchar **out_provider_name,
    gchar **out_roaming_text,
    MbimRegistrationFlag *out_registration_flag,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_provider_id = NULL;
    gchar *_provider_name = NULL;
    gchar *_roaming_text = NULL;

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

    /* Read the 'NwError' variable */
    {
        if (out_nw_error != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_nw_error = (MbimNwError)aux;
        }
        offset += 4;
    }

    /* Read the 'RegisterState' variable */
    {
        if (out_register_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_register_state = (MbimRegisterState)aux;
        }
        offset += 4;
    }

    /* Read the 'RegisterMode' variable */
    {
        if (out_register_mode != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_register_mode = (MbimRegisterMode)aux;
        }
        offset += 4;
    }

    /* Read the 'AvailableDataClasses' variable */
    {
        if (out_available_data_classes != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_available_data_classes = (MbimDataClass)aux;
        }
        offset += 4;
    }

    /* Read the 'CurrentCellularClass' variable */
    {
        if (out_current_cellular_class != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_current_cellular_class = (MbimCellularClass)aux;
        }
        offset += 4;
    }

    /* Read the 'ProviderId' variable */
    {
        if ((out_provider_id != NULL) && !_mbim_message_read_string (message, 0, offset, &_provider_id, error))
            goto out;
        offset += 8;
    }

    /* Read the 'ProviderName' variable */
    {
        if ((out_provider_name != NULL) && !_mbim_message_read_string (message, 0, offset, &_provider_name, error))
            goto out;
        offset += 8;
    }

    /* Read the 'RoamingText' variable */
    {
        if ((out_roaming_text != NULL) && !_mbim_message_read_string (message, 0, offset, &_roaming_text, error))
            goto out;
        offset += 8;
    }

    /* Read the 'RegistrationFlag' variable */
    {
        if (out_registration_flag != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_registration_flag = (MbimRegistrationFlag)aux;
        }
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_provider_id != NULL)
            *out_provider_id = _provider_id;
        if (out_provider_name != NULL)
            *out_provider_name = _provider_name;
        if (out_roaming_text != NULL)
            *out_roaming_text = _roaming_text;
    } else {
        g_free (_provider_id);
        g_free (_provider_name);
        g_free (_roaming_text);
    }

    return success;
}

static gchar *
mbim_message_atds_register_state_response_get_printable (
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

    g_string_append_printf (str, "%s  NwError = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_NW_ERROR_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_nw_error_get_string ((MbimNwError)tmp));
#elif defined __MBIM_NW_ERROR_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_nw_error_build_string_from_mask ((MbimNwError)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_state_get_string ((MbimRegisterState)tmp));
#elif defined __MBIM_REGISTER_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_state_build_string_from_mask ((MbimRegisterState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegisterMode = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTER_MODE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_register_mode_get_string ((MbimRegisterMode)tmp));
#elif defined __MBIM_REGISTER_MODE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_register_mode_build_string_from_mask ((MbimRegisterMode)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  AvailableDataClasses = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_DATA_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_data_class_get_string ((MbimDataClass)tmp));
#elif defined __MBIM_DATA_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_data_class_build_string_from_mask ((MbimDataClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CurrentCellularClass = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_CELLULAR_CLASS_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_cellular_class_get_string ((MbimCellularClass)tmp));
#elif defined __MBIM_CELLULAR_CLASS_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_cellular_class_build_string_from_mask ((MbimCellularClass)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderId = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ProviderName = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RoamingText = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  RegistrationFlag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_REGISTRATION_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_registration_flag_get_string ((MbimRegistrationFlag)tmp));
#elif defined __MBIM_REGISTRATION_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_registration_flag_build_string_from_mask ((MbimRegistrationFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

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
    [MBIM_CID_ATDS_SIGNAL] = {
        .query_cb = mbim_message_atds_signal_query_get_printable,
        .response_cb = mbim_message_atds_signal_response_get_printable,
    },
    [MBIM_CID_ATDS_LOCATION] = {
        .query_cb = mbim_message_atds_location_query_get_printable,
        .response_cb = mbim_message_atds_location_response_get_printable,
    },
    [MBIM_CID_ATDS_OPERATORS] = {
        .query_cb = mbim_message_atds_operators_query_get_printable,
        .response_cb = mbim_message_atds_operators_response_get_printable,
    },
    [MBIM_CID_ATDS_RAT] = {
        .query_cb = mbim_message_atds_rat_query_get_printable,
        .set_cb = mbim_message_atds_rat_set_get_printable,
        .response_cb = mbim_message_atds_rat_response_get_printable,
    },
    [MBIM_CID_ATDS_REGISTER_STATE] = {
        .query_cb = mbim_message_atds_register_state_query_get_printable,
        .response_cb = mbim_message_atds_register_state_response_get_printable,
    },
};

gchar *
__mbim_message_atds_get_printable_fields (
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

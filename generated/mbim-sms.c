
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

#include "mbim-sms.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Struct: MbimSmsPduReadRecord */

static void
_mbim_sms_pdu_read_record_free (MbimSmsPduReadRecord *var)
{
    if (!var)
        return;

    g_free (var->pdu_data);
    g_free (var);
}

void
mbim_sms_pdu_read_record_array_free (MbimSmsPduReadRecordArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_sms_pdu_read_record_free (array[i]);
    g_free (array);
}

static MbimSmsPduReadRecord *
_mbim_message_read_mbim_sms_pdu_read_record_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimSmsPduReadRecord *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimSmsPduReadRecord, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->message_index, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->message_status, error))
        goto out;
    offset += 4;

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, TRUE, TRUE, 0, &tmp, &(out->pdu_data_size), error))
            goto out;
        out->pdu_data = g_malloc (out->pdu_data_size);
        memcpy (out->pdu_data, tmp, out->pdu_data_size);
        offset += 8;
    }

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->pdu_data);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_sms_pdu_read_record_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimSmsPduReadRecordArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimSmsPduReadRecordArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimSmsPduReadRecord *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_sms_pdu_read_record_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_sms_pdu_read_record_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_sms_pdu_read_record_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_sms_pdu_read_record_struct (
    const MbimSmsPduReadRecord *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  MessageIndex = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->message_index);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  MessageStatus = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->message_status);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PduData = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->pdu_data_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->pdu_data[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_sms_pdu_read_record_struct_new (const MbimSmsPduReadRecord *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->message_index);
    _mbim_struct_builder_append_guint32 (builder, value->message_status);
    _mbim_struct_builder_append_byte_array (builder, TRUE, TRUE, TRUE, value->pdu_data, value->pdu_data_size);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_sms_pdu_read_record_struct (
    MbimStructBuilder *builder,
    const MbimSmsPduReadRecord *value)
{
    GByteArray *raw;

    raw = _mbim_sms_pdu_read_record_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_sms_pdu_read_record_struct (
    MbimMessageCommandBuilder *builder,
    const MbimSmsPduReadRecord *value)
{
    _mbim_struct_builder_append_mbim_sms_pdu_read_record_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_sms_pdu_read_record_struct_array (
    MbimStructBuilder *builder,
    const MbimSmsPduReadRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_sms_pdu_read_record_struct_new (values[i]);
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

            raw = _mbim_sms_pdu_read_record_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_sms_pdu_read_record_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimSmsPduReadRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_sms_pdu_read_record_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimSmsCdmaReadRecord */

static void
_mbim_sms_cdma_read_record_free (MbimSmsCdmaReadRecord *var)
{
    if (!var)
        return;

    g_free (var->address);
    g_free (var->timestamp);
    g_free (var->encoded_message);
    g_free (var);
}

void
mbim_sms_cdma_read_record_array_free (MbimSmsCdmaReadRecordArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_sms_cdma_read_record_free (array[i]);
    g_free (array);
}

static MbimSmsCdmaReadRecord *
_mbim_message_read_mbim_sms_cdma_read_record_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimSmsCdmaReadRecord *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimSmsCdmaReadRecord, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->message_index, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->message_status, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->address, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->timestamp, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->encoding, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->language, error))
        goto out;
    offset += 4;

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, TRUE, TRUE, 0, &tmp, &(out->encoded_message_size), error))
            goto out;
        out->encoded_message = g_malloc (out->encoded_message_size);
        memcpy (out->encoded_message, tmp, out->encoded_message_size);
        offset += 8;
    }

    if (!_mbim_message_read_guint32 (self, offset, &out->encoded_message_size_in_characters, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->address);
    g_free (out->timestamp);
    g_free (out->encoded_message);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_sms_cdma_read_record_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimSmsCdmaReadRecordArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimSmsCdmaReadRecordArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimSmsCdmaReadRecord *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_sms_cdma_read_record_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_sms_cdma_read_record_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_sms_cdma_read_record_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_sms_cdma_read_record_struct (
    const MbimSmsCdmaReadRecord *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  MessageIndex = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->message_index);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  MessageStatus = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->message_status);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Address = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->address);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Timestamp = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->timestamp);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Encoding = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->encoding);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Language = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->language);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  EncodedMessage = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->encoded_message_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->encoded_message[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  EncodedMessageSizeInCharacters = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->encoded_message_size_in_characters);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_sms_cdma_read_record_struct_new (const MbimSmsCdmaReadRecord *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->message_index);
    _mbim_struct_builder_append_guint32 (builder, value->message_status);
    _mbim_struct_builder_append_string (builder, value->address);
    _mbim_struct_builder_append_string (builder, value->timestamp);
    _mbim_struct_builder_append_guint32 (builder, value->encoding);
    _mbim_struct_builder_append_guint32 (builder, value->language);
    _mbim_struct_builder_append_byte_array (builder, TRUE, TRUE, TRUE, value->encoded_message, value->encoded_message_size);
    _mbim_struct_builder_append_guint32 (builder, value->encoded_message_size_in_characters);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_sms_cdma_read_record_struct (
    MbimStructBuilder *builder,
    const MbimSmsCdmaReadRecord *value)
{
    GByteArray *raw;

    raw = _mbim_sms_cdma_read_record_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_sms_cdma_read_record_struct (
    MbimMessageCommandBuilder *builder,
    const MbimSmsCdmaReadRecord *value)
{
    _mbim_struct_builder_append_mbim_sms_cdma_read_record_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_sms_cdma_read_record_struct_array (
    MbimStructBuilder *builder,
    const MbimSmsCdmaReadRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_sms_cdma_read_record_struct_new (values[i]);
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

            raw = _mbim_sms_cdma_read_record_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_sms_cdma_read_record_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimSmsCdmaReadRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_sms_cdma_read_record_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimSmsPduSendRecord */

static void
_mbim_sms_pdu_send_record_free (MbimSmsPduSendRecord *var)
{
    if (!var)
        return;

    g_free (var->pdu_data);
    g_free (var);
}

void
mbim_sms_pdu_send_record_free (MbimSmsPduSendRecord *var)
{
    _mbim_sms_pdu_send_record_free (var);
}

static MbimSmsPduSendRecord *
_mbim_message_read_mbim_sms_pdu_send_record_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimSmsPduSendRecord *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimSmsPduSendRecord, 1);

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, TRUE, TRUE, 0, &tmp, &(out->pdu_data_size), error))
            goto out;
        out->pdu_data = g_malloc (out->pdu_data_size);
        memcpy (out->pdu_data, tmp, out->pdu_data_size);
        offset += 8;
    }

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->pdu_data);
    g_free (out);
    return NULL;
}

static gchar *
_mbim_message_print_mbim_sms_pdu_send_record_struct (
    const MbimSmsPduSendRecord *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PduData = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->pdu_data_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->pdu_data[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_sms_pdu_send_record_struct_new (const MbimSmsPduSendRecord *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_byte_array (builder, TRUE, TRUE, TRUE, value->pdu_data, value->pdu_data_size);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_sms_pdu_send_record_struct (
    MbimStructBuilder *builder,
    const MbimSmsPduSendRecord *value)
{
    GByteArray *raw;

    raw = _mbim_sms_pdu_send_record_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_sms_pdu_send_record_struct (
    MbimMessageCommandBuilder *builder,
    const MbimSmsPduSendRecord *value)
{
    _mbim_struct_builder_append_mbim_sms_pdu_send_record_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_sms_pdu_send_record_struct_array (
    MbimStructBuilder *builder,
    const MbimSmsPduSendRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_sms_pdu_send_record_struct_new (values[i]);
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

            raw = _mbim_sms_pdu_send_record_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_sms_pdu_send_record_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimSmsPduSendRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_sms_pdu_send_record_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimSmsCdmaSendRecord */

static void
_mbim_sms_cdma_send_record_free (MbimSmsCdmaSendRecord *var)
{
    if (!var)
        return;

    g_free (var->address);
    g_free (var->encoded_message);
    g_free (var);
}

void
mbim_sms_cdma_send_record_free (MbimSmsCdmaSendRecord *var)
{
    _mbim_sms_cdma_send_record_free (var);
}

static MbimSmsCdmaSendRecord *
_mbim_message_read_mbim_sms_cdma_send_record_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimSmsCdmaSendRecord *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimSmsCdmaSendRecord, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->encoding, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->language, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->address, error))
        goto out;
    offset += 8;

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, TRUE, TRUE, 0, &tmp, &(out->encoded_message_size), error))
            goto out;
        out->encoded_message = g_malloc (out->encoded_message_size);
        memcpy (out->encoded_message, tmp, out->encoded_message_size);
        offset += 8;
    }

    if (!_mbim_message_read_guint32 (self, offset, &out->encoded_message_size_in_characters, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->address);
    g_free (out->encoded_message);
    g_free (out);
    return NULL;
}

static gchar *
_mbim_message_print_mbim_sms_cdma_send_record_struct (
    const MbimSmsCdmaSendRecord *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Encoding = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->encoding);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Language = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->language);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Address = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->address);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  EncodedMessage = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->encoded_message_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->encoded_message[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  EncodedMessageSizeInCharacters = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->encoded_message_size_in_characters);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_sms_cdma_send_record_struct_new (const MbimSmsCdmaSendRecord *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->encoding);
    _mbim_struct_builder_append_guint32 (builder, value->language);
    _mbim_struct_builder_append_string (builder, value->address);
    _mbim_struct_builder_append_byte_array (builder, TRUE, TRUE, TRUE, value->encoded_message, value->encoded_message_size);
    _mbim_struct_builder_append_guint32 (builder, value->encoded_message_size_in_characters);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_sms_cdma_send_record_struct (
    MbimStructBuilder *builder,
    const MbimSmsCdmaSendRecord *value)
{
    GByteArray *raw;

    raw = _mbim_sms_cdma_send_record_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_sms_cdma_send_record_struct (
    MbimMessageCommandBuilder *builder,
    const MbimSmsCdmaSendRecord *value)
{
    _mbim_struct_builder_append_mbim_sms_cdma_send_record_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_sms_cdma_send_record_struct_array (
    MbimStructBuilder *builder,
    const MbimSmsCdmaSendRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_sms_cdma_send_record_struct_new (values[i]);
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

            raw = _mbim_sms_cdma_send_record_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_sms_cdma_send_record_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimSmsCdmaSendRecord *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_sms_cdma_send_record_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Message (Query): MBIM Message SMS Configuration */

MbimMessage *
mbim_message_sms_configuration_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_SMS,
                                                 MBIM_CID_SMS_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_sms_configuration_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message SMS Configuration */

MbimMessage *
mbim_message_sms_configuration_set_new (
    MbimSmsFormat format,
    const gchar *sc_address,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_SMS,
                                                 MBIM_CID_SMS_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, format);
    }
    {
        _mbim_message_command_builder_append_string (builder, sc_address);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_sms_configuration_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Format = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_FORMAT_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_format_get_string ((MbimSmsFormat)tmp));
#elif defined __MBIM_SMS_FORMAT_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_format_build_string_from_mask ((MbimSmsFormat)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ScAddress = ", line_prefix);
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
/* Message (Response): MBIM Message SMS Configuration */

gboolean
mbim_message_sms_configuration_response_parse (
    const MbimMessage *message,
    MbimSmsStorageState *out_sms_storage_state,
    MbimSmsFormat *out_format,
    guint32 *out_max_messages,
    guint32 *out_cdma_short_message_size,
    gchar **out_sc_address,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    gchar *_sc_address = NULL;

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

    /* Read the 'SmsStorageState' variable */
    {
        if (out_sms_storage_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_sms_storage_state = (MbimSmsStorageState)aux;
        }
        offset += 4;
    }

    /* Read the 'Format' variable */
    {
        if (out_format != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_format = (MbimSmsFormat)aux;
        }
        offset += 4;
    }

    /* Read the 'MaxMessages' variable */
    {
        if ((out_max_messages != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_messages, error))
            goto out;
        offset += 4;
    }

    /* Read the 'CdmaShortMessageSize' variable */
    {
        if ((out_cdma_short_message_size != NULL) && !_mbim_message_read_guint32 (message, offset, out_cdma_short_message_size, error))
            goto out;
        offset += 4;
    }

    /* Read the 'ScAddress' variable */
    {
        if ((out_sc_address != NULL) && !_mbim_message_read_string (message, 0, offset, &_sc_address, error))
            goto out;
        offset += 8;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_sc_address != NULL)
            *out_sc_address = _sc_address;
    } else {
        g_free (_sc_address);
    }

    return success;
}

static gchar *
mbim_message_sms_configuration_response_get_printable (
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

    g_string_append_printf (str, "%s  SmsStorageState = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_STORAGE_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_storage_state_get_string ((MbimSmsStorageState)tmp));
#elif defined __MBIM_SMS_STORAGE_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_storage_state_build_string_from_mask ((MbimSmsStorageState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Format = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_FORMAT_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_format_get_string ((MbimSmsFormat)tmp));
#elif defined __MBIM_SMS_FORMAT_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_format_build_string_from_mask ((MbimSmsFormat)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxMessages = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CdmaShortMessageSize = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ScAddress = ", line_prefix);
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
/* Message (Query): MBIM Message SMS Read */

MbimMessage *
mbim_message_sms_read_query_new (
    MbimSmsFormat format,
    MbimSmsFlag flag,
    guint32 message_index,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_SMS,
                                                 MBIM_CID_SMS_READ,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_guint32 (builder, format);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, flag);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, message_index);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_sms_read_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Format = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_FORMAT_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_format_get_string ((MbimSmsFormat)tmp));
#elif defined __MBIM_SMS_FORMAT_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_format_build_string_from_mask ((MbimSmsFormat)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Flag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_flag_get_string ((MbimSmsFlag)tmp));
#elif defined __MBIM_SMS_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_flag_build_string_from_mask ((MbimSmsFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MessageIndex = ", line_prefix);
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
/* Message (Response): MBIM Message SMS Read */

gboolean
mbim_message_sms_read_response_parse (
    const MbimMessage *message,
    MbimSmsFormat *out_format,
    guint32 *out_messages_count,
    MbimSmsPduReadRecordArray **out_pdu_messages,
    MbimSmsCdmaReadRecordArray **out_cdma_messages,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _format;
    guint32 _messages_count;
    MbimSmsPduReadRecord **_pdu_messages = NULL;
    MbimSmsCdmaReadRecord **_cdma_messages = NULL;

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

    /* Read the 'Format' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_format, error))
            goto out;
        if (out_format != NULL)
            *out_format = _format;
        offset += 4;
    }

    /* Read the 'MessagesCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_messages_count, error))
            goto out;
        if (out_messages_count != NULL)
            *out_messages_count = _messages_count;
        offset += 4;
    }

    /* Read the 'PduMessages' variable */
    if (!(_format == MBIM_SMS_FORMAT_PDU)) {
        if (out_pdu_messages != NULL)
            *out_pdu_messages = NULL;
    } else {
        if ((out_pdu_messages != NULL) && !_mbim_message_read_mbim_sms_pdu_read_record_struct_array (message, _messages_count, offset, TRUE, &_pdu_messages, error))
            goto out;
        offset += (8 * _messages_count);
    }

    /* Read the 'CdmaMessages' variable */
    if (!(_format == MBIM_SMS_FORMAT_CDMA)) {
        if (out_cdma_messages != NULL)
            *out_cdma_messages = NULL;
    } else {
        if ((out_cdma_messages != NULL) && !_mbim_message_read_mbim_sms_cdma_read_record_struct_array (message, _messages_count, offset, TRUE, &_cdma_messages, error))
            goto out;
        offset += (8 * _messages_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_pdu_messages != NULL)
            *out_pdu_messages = _pdu_messages;
        if (out_cdma_messages != NULL)
            *out_cdma_messages = _cdma_messages;
    } else {
        mbim_sms_pdu_read_record_array_free (_pdu_messages);
        mbim_sms_cdma_read_record_array_free (_cdma_messages);
    }

    return success;
}

static gchar *
mbim_message_sms_read_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _format;
    guint32 _messages_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Format = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_format, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _format);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MessagesCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_messages_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _messages_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PduMessages = ", line_prefix);
    if (_format == MBIM_SMS_FORMAT_PDU) {
        g_autoptr(MbimSmsPduReadRecordArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_sms_pdu_read_record_struct_array (message, _messages_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _messages_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _messages_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_sms_pdu_read_record_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CdmaMessages = ", line_prefix);
    if (_format == MBIM_SMS_FORMAT_CDMA) {
        g_autoptr(MbimSmsCdmaReadRecordArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_sms_cdma_read_record_struct_array (message, _messages_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _messages_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _messages_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_sms_cdma_read_record_struct (tmp[i], new_line_prefix);
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
/* Message (Notification): MBIM Message SMS Read */

gboolean
mbim_message_sms_read_notification_parse (
    const MbimMessage *message,
    MbimSmsFormat *out_format,
    guint32 *out_messages_count,
    MbimSmsPduReadRecordArray **out_pdu_messages,
    MbimSmsCdmaReadRecordArray **out_cdma_messages,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _format;
    guint32 _messages_count;
    MbimSmsPduReadRecord **_pdu_messages = NULL;
    MbimSmsCdmaReadRecord **_cdma_messages = NULL;

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

    /* Read the 'Format' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_format, error))
            goto out;
        if (out_format != NULL)
            *out_format = _format;
        offset += 4;
    }

    /* Read the 'MessagesCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_messages_count, error))
            goto out;
        if (out_messages_count != NULL)
            *out_messages_count = _messages_count;
        offset += 4;
    }

    /* Read the 'PduMessages' variable */
    if (!(_format == MBIM_SMS_FORMAT_PDU)) {
        if (out_pdu_messages != NULL)
            *out_pdu_messages = NULL;
    } else {
        if ((out_pdu_messages != NULL) && !_mbim_message_read_mbim_sms_pdu_read_record_struct_array (message, _messages_count, offset, TRUE, &_pdu_messages, error))
            goto out;
        offset += (8 * _messages_count);
    }

    /* Read the 'CdmaMessages' variable */
    if (!(_format == MBIM_SMS_FORMAT_CDMA)) {
        if (out_cdma_messages != NULL)
            *out_cdma_messages = NULL;
    } else {
        if ((out_cdma_messages != NULL) && !_mbim_message_read_mbim_sms_cdma_read_record_struct_array (message, _messages_count, offset, TRUE, &_cdma_messages, error))
            goto out;
        offset += (8 * _messages_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_pdu_messages != NULL)
            *out_pdu_messages = _pdu_messages;
        if (out_cdma_messages != NULL)
            *out_cdma_messages = _cdma_messages;
    } else {
        mbim_sms_pdu_read_record_array_free (_pdu_messages);
        mbim_sms_cdma_read_record_array_free (_cdma_messages);
    }

    return success;
}

static gchar *
mbim_message_sms_read_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _format;
    guint32 _messages_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Format = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_format, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _format);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MessagesCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_messages_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _messages_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PduMessages = ", line_prefix);
    if (_format == MBIM_SMS_FORMAT_PDU) {
        g_autoptr(MbimSmsPduReadRecordArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_sms_pdu_read_record_struct_array (message, _messages_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _messages_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _messages_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_sms_pdu_read_record_struct (tmp[i], new_line_prefix);
            g_string_append (str, struct_str);
            g_string_append_printf (str, "%s    },\n", line_prefix);
        }
        g_string_append_printf (str, "%s  }'", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CdmaMessages = ", line_prefix);
    if (_format == MBIM_SMS_FORMAT_CDMA) {
        g_autoptr(MbimSmsCdmaReadRecordArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_sms_cdma_read_record_struct_array (message, _messages_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _messages_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _messages_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_sms_cdma_read_record_struct (tmp[i], new_line_prefix);
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
/* Message (Set): MBIM Message SMS Send */

MbimMessage *
mbim_message_sms_send_set_new (
    MbimSmsFormat format,
    const MbimSmsPduSendRecord *pdu_message,
    const MbimSmsCdmaSendRecord *cdma_message,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_SMS,
                                                 MBIM_CID_SMS_SEND,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, format);
    }
    if (format == MBIM_SMS_FORMAT_PDU) {
        _mbim_message_command_builder_append_mbim_sms_pdu_send_record_struct (builder, pdu_message);
    }
    if (format == MBIM_SMS_FORMAT_CDMA) {
        _mbim_message_command_builder_append_mbim_sms_cdma_send_record_struct (builder, cdma_message);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_sms_send_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _format;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Format = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_format, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _format);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  PduMessage = ", line_prefix);
    if (_format == MBIM_SMS_FORMAT_PDU) {
        g_autoptr(MbimSmsPduSendRecord) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_sms_pdu_send_record_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_sms_pdu_send_record_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  CdmaMessage = ", line_prefix);
    if (_format == MBIM_SMS_FORMAT_CDMA) {
        g_autoptr(MbimSmsCdmaSendRecord) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_sms_cdma_send_record_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_sms_cdma_send_record_struct (tmp, new_line_prefix);
        g_string_append (str, struct_str);
        g_string_append_printf (str, "%s  }\n", line_prefix);
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
/* Message (Response): MBIM Message SMS Send */

gboolean
mbim_message_sms_send_response_parse (
    const MbimMessage *message,
    guint32 *out_message_reference,
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

    /* Read the 'MessageReference' variable */
    {
        if ((out_message_reference != NULL) && !_mbim_message_read_guint32 (message, offset, out_message_reference, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_sms_send_response_get_printable (
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

    g_string_append_printf (str, "%s  MessageReference = ", line_prefix);
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
/* Message (Set): MBIM Message SMS Delete */

MbimMessage *
mbim_message_sms_delete_set_new (
    MbimSmsFlag flag,
    guint32 message_index,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_SMS,
                                                 MBIM_CID_SMS_DELETE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, flag);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, message_index);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_sms_delete_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Flag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_flag_get_string ((MbimSmsFlag)tmp));
#elif defined __MBIM_SMS_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_flag_build_string_from_mask ((MbimSmsFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MessageIndex = ", line_prefix);
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
/* Message (Response): MBIM Message SMS Delete */

gboolean
mbim_message_sms_delete_response_parse (
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
mbim_message_sms_delete_response_get_printable (
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

/*****************************************************************************/
/* Message (Query): MBIM Message SMS Message Store Status */

MbimMessage *
mbim_message_sms_message_store_status_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_SMS,
                                                 MBIM_CID_SMS_MESSAGE_STORE_STATUS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_sms_message_store_status_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message SMS Message Store Status */

gboolean
mbim_message_sms_message_store_status_response_parse (
    const MbimMessage *message,
    MbimSmsStatusFlag *out_flag,
    guint32 *out_message_index,
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

    /* Read the 'Flag' variable */
    {
        if (out_flag != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_flag = (MbimSmsStatusFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'MessageIndex' variable */
    {
        if ((out_message_index != NULL) && !_mbim_message_read_guint32 (message, offset, out_message_index, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_sms_message_store_status_response_get_printable (
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

    g_string_append_printf (str, "%s  Flag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_STATUS_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_status_flag_get_string ((MbimSmsStatusFlag)tmp));
#elif defined __MBIM_SMS_STATUS_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_status_flag_build_string_from_mask ((MbimSmsStatusFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MessageIndex = ", line_prefix);
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
/* Message (Notification): MBIM Message SMS Message Store Status */

gboolean
mbim_message_sms_message_store_status_notification_parse (
    const MbimMessage *message,
    MbimSmsStatusFlag *out_flag,
    guint32 *out_message_index,
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

    /* Read the 'Flag' variable */
    {
        if (out_flag != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_flag = (MbimSmsStatusFlag)aux;
        }
        offset += 4;
    }

    /* Read the 'MessageIndex' variable */
    {
        if ((out_message_index != NULL) && !_mbim_message_read_guint32 (message, offset, out_message_index, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_sms_message_store_status_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Flag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_SMS_STATUS_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_sms_status_flag_get_string ((MbimSmsStatusFlag)tmp));
#elif defined __MBIM_SMS_STATUS_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_sms_status_flag_build_string_from_mask ((MbimSmsStatusFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MessageIndex = ", line_prefix);
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
    [MBIM_CID_SMS_CONFIGURATION] = {
        .query_cb = mbim_message_sms_configuration_query_get_printable,
        .set_cb = mbim_message_sms_configuration_set_get_printable,
        .response_cb = mbim_message_sms_configuration_response_get_printable,
    },
    [MBIM_CID_SMS_READ] = {
        .query_cb = mbim_message_sms_read_query_get_printable,
        .response_cb = mbim_message_sms_read_response_get_printable,
        .notification_cb = mbim_message_sms_read_notification_get_printable,
    },
    [MBIM_CID_SMS_SEND] = {
        .set_cb = mbim_message_sms_send_set_get_printable,
        .response_cb = mbim_message_sms_send_response_get_printable,
    },
    [MBIM_CID_SMS_DELETE] = {
        .set_cb = mbim_message_sms_delete_set_get_printable,
        .response_cb = mbim_message_sms_delete_response_get_printable,
    },
    [MBIM_CID_SMS_MESSAGE_STORE_STATUS] = {
        .query_cb = mbim_message_sms_message_store_status_query_get_printable,
        .response_cb = mbim_message_sms_message_store_status_response_get_printable,
        .notification_cb = mbim_message_sms_message_store_status_notification_get_printable,
    },
};

gchar *
__mbim_message_sms_get_printable_fields (
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

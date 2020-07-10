
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

#include "mbim-ms-basic-connect-extensions.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Struct: MbimPcoValue */

static void
_mbim_pco_value_free (MbimPcoValue *var)
{
    if (!var)
        return;

    g_free (var->pco_data_buffer);
    g_free (var);
}

void
mbim_pco_value_free (MbimPcoValue *var)
{
    _mbim_pco_value_free (var);
}

static MbimPcoValue *
_mbim_message_read_mbim_pco_value_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimPcoValue *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimPcoValue, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->session_id, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->pco_data_size, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->pco_data_type, error))
        goto out;
    offset += 4;

    {
        const guint8 *tmp;

        if (!_mbim_message_read_byte_array (self, relative_offset, offset, FALSE, FALSE, out->pco_data_size, &tmp, NULL, error))
            goto out;
        out->pco_data_buffer = g_malloc (out->pco_data_size);
        memcpy (out->pco_data_buffer, tmp, out->pco_data_size);
        offset += 4;
    }

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->pco_data_buffer);
    g_free (out);
    return NULL;
}

static gchar *
_mbim_message_print_mbim_pco_value_struct (
    const MbimPcoValue *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SessionId = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->session_id);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PcoDataSize = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->pco_data_size);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PcoDataType = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->pco_data_type);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  PcoDataBuffer = ", line_prefix);
    {
        guint i;
        guint array_size;

        array_size = self->pco_data_size;
        g_string_append (str, "'");
        for (i = 0; i < array_size; i++)
            g_string_append_printf (str, "%02x%s", self->pco_data_buffer[i], (i == (array_size - 1)) ? "" : ":" );
        g_string_append (str, "'");
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_pco_value_struct_new (const MbimPcoValue *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->session_id);
    _mbim_struct_builder_append_guint32 (builder, value->pco_data_size);
    _mbim_struct_builder_append_guint32 (builder, value->pco_data_type);
    _mbim_struct_builder_append_byte_array (builder, FALSE, FALSE, TRUE, value->pco_data_buffer, value->pco_data_size);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_pco_value_struct (
    MbimStructBuilder *builder,
    const MbimPcoValue *value)
{
    GByteArray *raw;

    raw = _mbim_pco_value_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_pco_value_struct (
    MbimMessageCommandBuilder *builder,
    const MbimPcoValue *value)
{
    _mbim_struct_builder_append_mbim_pco_value_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_pco_value_struct_array (
    MbimStructBuilder *builder,
    const MbimPcoValue *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_pco_value_struct_new (values[i]);
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

            raw = _mbim_pco_value_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_pco_value_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimPcoValue *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_pco_value_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimLteAttachConfiguration */

static void
_mbim_lte_attach_configuration_free (MbimLteAttachConfiguration *var)
{
    if (!var)
        return;

    g_free (var->access_string);
    g_free (var->user_name);
    g_free (var->password);
    g_free (var);
}

void
mbim_lte_attach_configuration_array_free (MbimLteAttachConfigurationArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_lte_attach_configuration_free (array[i]);
    g_free (array);
}

static MbimLteAttachConfiguration *
_mbim_message_read_mbim_lte_attach_configuration_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimLteAttachConfiguration *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimLteAttachConfiguration, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->ip_type, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->roaming, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->source, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->access_string, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->user_name, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->password, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->compression, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->auth_protocol, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->access_string);
    g_free (out->user_name);
    g_free (out->password);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_lte_attach_configuration_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimLteAttachConfigurationArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimLteAttachConfigurationArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimLteAttachConfiguration *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_lte_attach_configuration_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_lte_attach_configuration_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_lte_attach_configuration_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_lte_attach_configuration_struct (
    const MbimLteAttachConfiguration *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  IpType = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->ip_type);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Roaming = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->roaming);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Source = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->source);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  AccessString = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->access_string);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  UserName = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->user_name);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Password = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->password);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Compression = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->compression);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  AuthProtocol = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->auth_protocol);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_lte_attach_configuration_struct_new (const MbimLteAttachConfiguration *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->ip_type);
    _mbim_struct_builder_append_guint32 (builder, value->roaming);
    _mbim_struct_builder_append_guint32 (builder, value->source);
    _mbim_struct_builder_append_string (builder, value->access_string);
    _mbim_struct_builder_append_string (builder, value->user_name);
    _mbim_struct_builder_append_string (builder, value->password);
    _mbim_struct_builder_append_guint32 (builder, value->compression);
    _mbim_struct_builder_append_guint32 (builder, value->auth_protocol);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_lte_attach_configuration_struct (
    MbimStructBuilder *builder,
    const MbimLteAttachConfiguration *value)
{
    GByteArray *raw;

    raw = _mbim_lte_attach_configuration_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_lte_attach_configuration_struct (
    MbimMessageCommandBuilder *builder,
    const MbimLteAttachConfiguration *value)
{
    _mbim_struct_builder_append_mbim_lte_attach_configuration_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_lte_attach_configuration_struct_array (
    MbimStructBuilder *builder,
    const MbimLteAttachConfiguration *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_lte_attach_configuration_struct_new (values[i]);
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

            raw = _mbim_lte_attach_configuration_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_lte_attach_configuration_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimLteAttachConfiguration *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_lte_attach_configuration_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Struct: MbimLteAttachStatus */

static void
_mbim_lte_attach_status_free (MbimLteAttachStatus *var)
{
    if (!var)
        return;

    g_free (var->access_string);
    g_free (var->user_name);
    g_free (var->password);
    g_free (var);
}

void
mbim_lte_attach_status_free (MbimLteAttachStatus *var)
{
    _mbim_lte_attach_status_free (var);
}

static MbimLteAttachStatus *
_mbim_message_read_mbim_lte_attach_status_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimLteAttachStatus *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimLteAttachStatus, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->lte_attach_state, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->ip_type, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->access_string, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->user_name, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->password, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_guint32 (self, offset, &out->compression, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_guint32 (self, offset, &out->auth_protocol, error))
        goto out;
    offset += 4;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->access_string);
    g_free (out->user_name);
    g_free (out->password);
    g_free (out);
    return NULL;
}

static gchar *
_mbim_message_print_mbim_lte_attach_status_struct (
    const MbimLteAttachStatus *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  LteAttachState = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->lte_attach_state);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  IpType = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->ip_type);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  AccessString = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->access_string);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  UserName = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->user_name);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Password = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->password);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Compression = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->compression);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  AuthProtocol = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->auth_protocol);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_lte_attach_status_struct_new (const MbimLteAttachStatus *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->lte_attach_state);
    _mbim_struct_builder_append_guint32 (builder, value->ip_type);
    _mbim_struct_builder_append_string (builder, value->access_string);
    _mbim_struct_builder_append_string (builder, value->user_name);
    _mbim_struct_builder_append_string (builder, value->password);
    _mbim_struct_builder_append_guint32 (builder, value->compression);
    _mbim_struct_builder_append_guint32 (builder, value->auth_protocol);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_lte_attach_status_struct (
    MbimStructBuilder *builder,
    const MbimLteAttachStatus *value)
{
    GByteArray *raw;

    raw = _mbim_lte_attach_status_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_lte_attach_status_struct (
    MbimMessageCommandBuilder *builder,
    const MbimLteAttachStatus *value)
{
    _mbim_struct_builder_append_mbim_lte_attach_status_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_lte_attach_status_struct_array (
    MbimStructBuilder *builder,
    const MbimLteAttachStatus *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_lte_attach_status_struct_new (values[i]);
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

            raw = _mbim_lte_attach_status_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_lte_attach_status_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimLteAttachStatus *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_lte_attach_status_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Ms Basic Connect Extensions PCO */

MbimMessage *
mbim_message_ms_basic_connect_extensions_pco_query_new (
    const MbimPcoValue *pco_value,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_MS_BASIC_CONNECT_EXTENSIONS,
                                                 MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_PCO,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_mbim_pco_value_struct (builder, pco_value);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ms_basic_connect_extensions_pco_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PcoValue = ", line_prefix);
    {
        g_autoptr(MbimPcoValue) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pco_value_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pco_value_struct (tmp, new_line_prefix);
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
/* Message (Response): MBIM Message Ms Basic Connect Extensions PCO */

gboolean
mbim_message_ms_basic_connect_extensions_pco_response_parse (
    const MbimMessage *message,
    MbimPcoValue **out_pco_value,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    MbimPcoValue *_pco_value = NULL;

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

    /* Read the 'PcoValue' variable */
    {
        MbimPcoValue *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pco_value_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pco_value != NULL)
            _pco_value = tmp;
        else
             _mbim_pco_value_free (tmp);
        offset += bytes_read;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_pco_value != NULL)
            *out_pco_value = _pco_value;
    } else {
        mbim_pco_value_free (_pco_value);
    }

    return success;
}

static gchar *
mbim_message_ms_basic_connect_extensions_pco_response_get_printable (
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

    g_string_append_printf (str, "%s  PcoValue = ", line_prefix);
    {
        g_autoptr(MbimPcoValue) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pco_value_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pco_value_struct (tmp, new_line_prefix);
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
/* Message (Notification): MBIM Message Ms Basic Connect Extensions PCO */

gboolean
mbim_message_ms_basic_connect_extensions_pco_notification_parse (
    const MbimMessage *message,
    MbimPcoValue **out_pco_value,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    MbimPcoValue *_pco_value = NULL;

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

    /* Read the 'PcoValue' variable */
    {
        MbimPcoValue *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pco_value_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_pco_value != NULL)
            _pco_value = tmp;
        else
             _mbim_pco_value_free (tmp);
        offset += bytes_read;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_pco_value != NULL)
            *out_pco_value = _pco_value;
    } else {
        mbim_pco_value_free (_pco_value);
    }

    return success;
}

static gchar *
mbim_message_ms_basic_connect_extensions_pco_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  PcoValue = ", line_prefix);
    {
        g_autoptr(MbimPcoValue) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_pco_value_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_pco_value_struct (tmp, new_line_prefix);
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
/* Message (Query): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

MbimMessage *
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_MS_BASIC_CONNECT_EXTENSIONS,
                                                 MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Set): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

MbimMessage *
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_set_new (
    MbimLteAttachContextOperation operation,
    guint32 configuration_count,
    const MbimLteAttachConfiguration *const *configurations,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_MS_BASIC_CONNECT_EXTENSIONS,
                                                 MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, operation);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, configuration_count);
    }
    {
        _mbim_message_command_builder_append_mbim_lte_attach_configuration_struct_array (builder, configurations, configuration_count, TRUE);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _configuration_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  Operation = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_LTE_ATTACH_CONTEXT_OPERATION_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_lte_attach_context_operation_get_string ((MbimLteAttachContextOperation)tmp));
#elif defined __MBIM_LTE_ATTACH_CONTEXT_OPERATION_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_lte_attach_context_operation_build_string_from_mask ((MbimLteAttachContextOperation)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  ConfigurationCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_configuration_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _configuration_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Configurations = ", line_prefix);
    {
        g_autoptr(MbimLteAttachConfigurationArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_lte_attach_configuration_struct_array (message, _configuration_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _configuration_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _configuration_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_lte_attach_configuration_struct (tmp[i], new_line_prefix);
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
/* Message (Response): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

gboolean
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_response_parse (
    const MbimMessage *message,
    guint32 *out_configuration_count,
    MbimLteAttachConfigurationArray **out_configurations,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _configuration_count;
    MbimLteAttachConfiguration **_configurations = NULL;

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

    /* Read the 'ConfigurationCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_configuration_count, error))
            goto out;
        if (out_configuration_count != NULL)
            *out_configuration_count = _configuration_count;
        offset += 4;
    }

    /* Read the 'Configurations' variable */
    {
        if ((out_configurations != NULL) && !_mbim_message_read_mbim_lte_attach_configuration_struct_array (message, _configuration_count, offset, TRUE, &_configurations, error))
            goto out;
        offset += (8 * _configuration_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_configurations != NULL)
            *out_configurations = _configurations;
    } else {
        mbim_lte_attach_configuration_array_free (_configurations);
    }

    return success;
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _configuration_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ConfigurationCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_configuration_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _configuration_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Configurations = ", line_prefix);
    {
        g_autoptr(MbimLteAttachConfigurationArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_lte_attach_configuration_struct_array (message, _configuration_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _configuration_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _configuration_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_lte_attach_configuration_struct (tmp[i], new_line_prefix);
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
/* Message (Notification): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

gboolean
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_notification_parse (
    const MbimMessage *message,
    guint32 *out_configuration_count,
    MbimLteAttachConfigurationArray **out_configurations,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _configuration_count;
    MbimLteAttachConfiguration **_configurations = NULL;

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

    /* Read the 'ConfigurationCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_configuration_count, error))
            goto out;
        if (out_configuration_count != NULL)
            *out_configuration_count = _configuration_count;
        offset += 4;
    }

    /* Read the 'Configurations' variable */
    {
        if ((out_configurations != NULL) && !_mbim_message_read_mbim_lte_attach_configuration_struct_array (message, _configuration_count, offset, TRUE, &_configurations, error))
            goto out;
        offset += (8 * _configuration_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_configurations != NULL)
            *out_configurations = _configurations;
    } else {
        mbim_lte_attach_configuration_array_free (_configurations);
    }

    return success;
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_configuration_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _configuration_count;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  ConfigurationCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_configuration_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _configuration_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Configurations = ", line_prefix);
    {
        g_autoptr(MbimLteAttachConfigurationArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_lte_attach_configuration_struct_array (message, _configuration_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _configuration_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _configuration_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_lte_attach_configuration_struct (tmp[i], new_line_prefix);
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
/* Message (Query): MBIM Message Ms Basic Connect Extensions Lte Attach Status */

MbimMessage *
mbim_message_ms_basic_connect_extensions_lte_attach_status_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_MS_BASIC_CONNECT_EXTENSIONS,
                                                 MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_STATUS,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_status_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Ms Basic Connect Extensions Lte Attach Status */

gboolean
mbim_message_ms_basic_connect_extensions_lte_attach_status_response_parse (
    const MbimMessage *message,
    MbimLteAttachStatus **out_lte_attach_status,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    MbimLteAttachStatus *_lte_attach_status = NULL;

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

    /* Read the 'LteAttachStatus' variable */
    {
        MbimLteAttachStatus *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_lte_attach_status_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_lte_attach_status != NULL)
            _lte_attach_status = tmp;
        else
             _mbim_lte_attach_status_free (tmp);
        offset += bytes_read;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_lte_attach_status != NULL)
            *out_lte_attach_status = _lte_attach_status;
    } else {
        mbim_lte_attach_status_free (_lte_attach_status);
    }

    return success;
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_status_response_get_printable (
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

    g_string_append_printf (str, "%s  LteAttachStatus = ", line_prefix);
    {
        g_autoptr(MbimLteAttachStatus) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_lte_attach_status_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_lte_attach_status_struct (tmp, new_line_prefix);
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
/* Message (Notification): MBIM Message Ms Basic Connect Extensions Lte Attach Status */

gboolean
mbim_message_ms_basic_connect_extensions_lte_attach_status_notification_parse (
    const MbimMessage *message,
    MbimLteAttachStatus **out_lte_attach_status,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    MbimLteAttachStatus *_lte_attach_status = NULL;

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

    /* Read the 'LteAttachStatus' variable */
    {
        MbimLteAttachStatus *tmp;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_lte_attach_status_struct (message, offset, &bytes_read, error);
        if (!tmp)
            goto out;
        if (out_lte_attach_status != NULL)
            _lte_attach_status = tmp;
        else
             _mbim_lte_attach_status_free (tmp);
        offset += bytes_read;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_lte_attach_status != NULL)
            *out_lte_attach_status = _lte_attach_status;
    } else {
        mbim_lte_attach_status_free (_lte_attach_status);
    }

    return success;
}

static gchar *
mbim_message_ms_basic_connect_extensions_lte_attach_status_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  LteAttachStatus = ", line_prefix);
    {
        g_autoptr(MbimLteAttachStatus) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        g_autofree gchar *struct_str = NULL;
        guint32 bytes_read = 0;

        tmp = _mbim_message_read_mbim_lte_attach_status_struct (message, offset, &bytes_read, &inner_error);
        if (!tmp)
            goto out;
        offset += bytes_read;
        g_string_append (str, "{\n");
        new_line_prefix = g_strdup_printf ("%s    ", line_prefix);
        struct_str = _mbim_message_print_mbim_lte_attach_status_struct (tmp, new_line_prefix);
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

typedef struct {
  gchar * (* query_cb)        (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* set_cb)          (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* response_cb)     (const MbimMessage *message, const gchar *line_prefix, GError **error);
  gchar * (* notification_cb) (const MbimMessage *message, const gchar *line_prefix, GError **error);
} GetPrintableCallbacks;

static const GetPrintableCallbacks get_printable_callbacks[] = {
    [MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_PCO] = {
        .query_cb = mbim_message_ms_basic_connect_extensions_pco_query_get_printable,
        .response_cb = mbim_message_ms_basic_connect_extensions_pco_response_get_printable,
        .notification_cb = mbim_message_ms_basic_connect_extensions_pco_notification_get_printable,
    },
    [MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_CONFIGURATION] = {
        .query_cb = mbim_message_ms_basic_connect_extensions_lte_attach_configuration_query_get_printable,
        .set_cb = mbim_message_ms_basic_connect_extensions_lte_attach_configuration_set_get_printable,
        .response_cb = mbim_message_ms_basic_connect_extensions_lte_attach_configuration_response_get_printable,
        .notification_cb = mbim_message_ms_basic_connect_extensions_lte_attach_configuration_notification_get_printable,
    },
    [MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_STATUS] = {
        .query_cb = mbim_message_ms_basic_connect_extensions_lte_attach_status_query_get_printable,
        .response_cb = mbim_message_ms_basic_connect_extensions_lte_attach_status_response_get_printable,
        .notification_cb = mbim_message_ms_basic_connect_extensions_lte_attach_status_notification_get_printable,
    },
};

gchar *
__mbim_message_ms_basic_connect_extensions_get_printable_fields (
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

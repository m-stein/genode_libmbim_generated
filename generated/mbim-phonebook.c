
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

#include "mbim-phonebook.h"
#include "mbim-message-private.h"
#include "mbim-enum-types.h"
#include "mbim-error-types.h"
#include "mbim-device.h"
#include "mbim-utils.h"

/*****************************************************************************/
/* Struct: MbimPhonebookEntry */

static void
_mbim_phonebook_entry_free (MbimPhonebookEntry *var)
{
    if (!var)
        return;

    g_free (var->number);
    g_free (var->name);
    g_free (var);
}

void
mbim_phonebook_entry_array_free (MbimPhonebookEntryArray *array)
{
    guint32 i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
        _mbim_phonebook_entry_free (array[i]);
    g_free (array);
}

static MbimPhonebookEntry *
_mbim_message_read_mbim_phonebook_entry_struct (
    const MbimMessage *self,
    guint32 relative_offset,
    guint32 *bytes_read,
    GError **error)
{
    gboolean success = FALSE;
    MbimPhonebookEntry *out;
    guint32 offset = relative_offset;

    g_assert (self != NULL);

    out = g_new0 (MbimPhonebookEntry, 1);

    if (!_mbim_message_read_guint32 (self, offset, &out->entry_index, error))
        goto out;
    offset += 4;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->number, error))
        goto out;
    offset += 8;

    if (!_mbim_message_read_string (self, relative_offset, offset, &out->name, error))
        goto out;
    offset += 8;

    success = TRUE;

 out:
    if (success) {
        if (bytes_read)
            *bytes_read = (offset - relative_offset);
        return out;
    }

    g_free (out->number);
    g_free (out->name);
    g_free (out);
    return NULL;
}

static gboolean
_mbim_message_read_mbim_phonebook_entry_struct_array (
    const MbimMessage *self,
    guint32 array_size,
    guint32 relative_offset_array_start,
    gboolean refs,
    MbimPhonebookEntryArray **out_array,
    GError **error)
{
    GError *inner_error = NULL;
    MbimPhonebookEntryArray *out;
    guint32 i;
    guint32 offset;

    if (!array_size) {
        *out_array = NULL;
        return TRUE;
    }

    out = g_new0 (MbimPhonebookEntry *, array_size + 1);

    if (!refs) {
        _mbim_message_read_guint32 (self, relative_offset_array_start, &offset, &inner_error);
        for (i = 0; !inner_error && (i < array_size); i++, offset += 0)
            out[i] = _mbim_message_read_mbim_phonebook_entry_struct (self, offset, NULL, &inner_error);
    } else {
        offset = relative_offset_array_start;
        for (i = 0; !inner_error && (i < array_size); i++, offset += 8) {
            guint32 tmp_offset;

            if (_mbim_message_read_guint32 (self, offset, &tmp_offset, &inner_error))
                out[i] = _mbim_message_read_mbim_phonebook_entry_struct (self, tmp_offset, NULL, &inner_error);
        }
    }

    if (!inner_error) {
        *out_array = out;
        return TRUE;
    }

    mbim_phonebook_entry_array_free (out);
    g_propagate_error (error, inner_error);
    return FALSE;
}

static gchar *
_mbim_message_print_mbim_phonebook_entry_struct (
    const MbimPhonebookEntry *self,
    const gchar *line_prefix)
{
    GString *str;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  EntryIndex = ", line_prefix);
    {
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", self->entry_index);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Number = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->number);
    }
    g_string_append (str, "\n");
    g_string_append_printf (str, "%s  Name = ", line_prefix);
    {
        g_string_append_printf (str, "'%s'", self->name);
    }
    g_string_append (str, "\n");
    return g_string_free (str, FALSE);
}

static GByteArray *
_mbim_phonebook_entry_struct_new (const MbimPhonebookEntry *value)
{
    MbimStructBuilder *builder;

    g_assert (value != NULL);

    builder = _mbim_struct_builder_new ();
    _mbim_struct_builder_append_guint32 (builder, value->entry_index);
    _mbim_struct_builder_append_string (builder, value->number);
    _mbim_struct_builder_append_string (builder, value->name);

    return _mbim_struct_builder_complete (builder);
}

static void
_mbim_struct_builder_append_mbim_phonebook_entry_struct (
    MbimStructBuilder *builder,
    const MbimPhonebookEntry *value)
{
    GByteArray *raw;

    raw = _mbim_phonebook_entry_struct_new (value);
    g_byte_array_append (builder->fixed_buffer, raw->data, raw->len);
    g_byte_array_unref (raw);
}

static void
_mbim_message_command_builder_append_mbim_phonebook_entry_struct (
    MbimMessageCommandBuilder *builder,
    const MbimPhonebookEntry *value)
{
    _mbim_struct_builder_append_mbim_phonebook_entry_struct (builder->contents_builder, value);
}

static void
_mbim_struct_builder_append_mbim_phonebook_entry_struct_array (
    MbimStructBuilder *builder,
    const MbimPhonebookEntry *const *values,
    guint32 n_values,
    gboolean refs)
{
    guint32 offset;
    guint32 i;
    GByteArray *raw_all = NULL;

    if (!refs) {
        for (i = 0; i < n_values; i++) {
            GByteArray *raw;

            raw = _mbim_phonebook_entry_struct_new (values[i]);
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

            raw = _mbim_phonebook_entry_struct_new (values[i]);
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
_mbim_message_command_builder_append_mbim_phonebook_entry_struct_array (
    MbimMessageCommandBuilder *builder,
    const MbimPhonebookEntry *const *values,
    guint32 n_values,
    gboolean refs)
{
    _mbim_struct_builder_append_mbim_phonebook_entry_struct_array (builder->contents_builder, values, n_values, refs);
}

/*****************************************************************************/
/* Message (Query): MBIM Message Phonebook Configuration */

MbimMessage *
mbim_message_phonebook_configuration_query_new (
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_PHONEBOOK,
                                                 MBIM_CID_PHONEBOOK_CONFIGURATION,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_phonebook_configuration_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;

    str = g_string_new ("");

    return g_string_free (str, FALSE);
}

/*****************************************************************************/
/* Message (Response): MBIM Message Phonebook Configuration */

gboolean
mbim_message_phonebook_configuration_response_parse (
    const MbimMessage *message,
    MbimPhonebookState *out_state,
    guint32 *out_number_of_entries,
    guint32 *out_used_entries,
    guint32 *out_max_number_length,
    guint32 *out_max_name,
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

    /* Read the 'State' variable */
    {
        if (out_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_state = (MbimPhonebookState)aux;
        }
        offset += 4;
    }

    /* Read the 'NumberOfEntries' variable */
    {
        if ((out_number_of_entries != NULL) && !_mbim_message_read_guint32 (message, offset, out_number_of_entries, error))
            goto out;
        offset += 4;
    }

    /* Read the 'UsedEntries' variable */
    {
        if ((out_used_entries != NULL) && !_mbim_message_read_guint32 (message, offset, out_used_entries, error))
            goto out;
        offset += 4;
    }

    /* Read the 'MaxNumberLength' variable */
    {
        if ((out_max_number_length != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_number_length, error))
            goto out;
        offset += 4;
    }

    /* Read the 'MaxName' variable */
    {
        if ((out_max_name != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_name, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_phonebook_configuration_response_get_printable (
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

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PHONEBOOK_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_phonebook_state_get_string ((MbimPhonebookState)tmp));
#elif defined __MBIM_PHONEBOOK_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_phonebook_state_build_string_from_mask ((MbimPhonebookState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NumberOfEntries = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  UsedEntries = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxNumberLength = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxName = ", line_prefix);
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
/* Message (Notification): MBIM Message Phonebook Configuration */

gboolean
mbim_message_phonebook_configuration_notification_parse (
    const MbimMessage *message,
    MbimPhonebookState *out_state,
    guint32 *out_number_of_entries,
    guint32 *out_used_entries,
    guint32 *out_max_number_length,
    guint32 *out_max_name,
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

    /* Read the 'State' variable */
    {
        if (out_state != NULL) {
            guint32 aux;

            if (!_mbim_message_read_guint32 (message, offset, &aux, error))
                goto out;
            *out_state = (MbimPhonebookState)aux;
        }
        offset += 4;
    }

    /* Read the 'NumberOfEntries' variable */
    {
        if ((out_number_of_entries != NULL) && !_mbim_message_read_guint32 (message, offset, out_number_of_entries, error))
            goto out;
        offset += 4;
    }

    /* Read the 'UsedEntries' variable */
    {
        if ((out_used_entries != NULL) && !_mbim_message_read_guint32 (message, offset, out_used_entries, error))
            goto out;
        offset += 4;
    }

    /* Read the 'MaxNumberLength' variable */
    {
        if ((out_max_number_length != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_number_length, error))
            goto out;
        offset += 4;
    }

    /* Read the 'MaxName' variable */
    {
        if ((out_max_name != NULL) && !_mbim_message_read_guint32 (message, offset, out_max_name, error))
            goto out;
        offset += 4;
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:


    return success;
}

static gchar *
mbim_message_phonebook_configuration_notification_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  State = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PHONEBOOK_STATE_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_phonebook_state_get_string ((MbimPhonebookState)tmp));
#elif defined __MBIM_PHONEBOOK_STATE_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_phonebook_state_build_string_from_mask ((MbimPhonebookState)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  NumberOfEntries = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  UsedEntries = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxNumberLength = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  MaxName = ", line_prefix);
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
/* Message (Query): MBIM Message Phonebook Read */

MbimMessage *
mbim_message_phonebook_read_query_new (
    MbimPhonebookFlag filter_flag,
    guint32 filter_message_index,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_PHONEBOOK,
                                                 MBIM_CID_PHONEBOOK_READ,
                                                 MBIM_MESSAGE_COMMAND_TYPE_QUERY);
    {
        _mbim_message_command_builder_append_guint32 (builder, filter_flag);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, filter_message_index);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_phonebook_read_query_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  FilterFlag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PHONEBOOK_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_phonebook_flag_get_string ((MbimPhonebookFlag)tmp));
#elif defined __MBIM_PHONEBOOK_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_phonebook_flag_build_string_from_mask ((MbimPhonebookFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  FilterMessageIndex = ", line_prefix);
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
/* Message (Response): MBIM Message Phonebook Read */

gboolean
mbim_message_phonebook_read_response_parse (
    const MbimMessage *message,
    guint32 *out_entry_count,
    MbimPhonebookEntryArray **out_entries,
    GError **error)
{
    gboolean success = FALSE;
    guint32 offset = 0;
    guint32 _entry_count;
    MbimPhonebookEntry **_entries = NULL;

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

    /* Read the 'EntryCount' variable */
    {
        if (!_mbim_message_read_guint32 (message, offset, &_entry_count, error))
            goto out;
        if (out_entry_count != NULL)
            *out_entry_count = _entry_count;
        offset += 4;
    }

    /* Read the 'Entries' variable */
    {
        if ((out_entries != NULL) && !_mbim_message_read_mbim_phonebook_entry_struct_array (message, _entry_count, offset, TRUE, &_entries, error))
            goto out;
        offset += (8 * _entry_count);
    }

    /* All variables successfully parsed */
    success = TRUE;

 out:

    if (success) {
        /* Memory allocated variables as output */
        if (out_entries != NULL)
            *out_entries = _entries;
    } else {
        mbim_phonebook_entry_array_free (_entries);
    }

    return success;
}

static gchar *
mbim_message_phonebook_read_response_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;
    guint32 _entry_count;

    if (!mbim_message_response_get_result (message, MBIM_MESSAGE_TYPE_COMMAND_DONE, NULL))
        return NULL;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  EntryCount = ", line_prefix);
    {
        if (!_mbim_message_read_guint32 (message, offset, &_entry_count, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", _entry_count);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Entries = ", line_prefix);
    {
        g_autoptr(MbimPhonebookEntryArray) tmp = NULL;
        g_autofree gchar *new_line_prefix = NULL;
        guint i;

        if (!_mbim_message_read_mbim_phonebook_entry_struct_array (message, _entry_count, offset, TRUE, &tmp, &inner_error))
            goto out;
        offset += (8 * _entry_count);
        new_line_prefix = g_strdup_printf ("%s        ", line_prefix);
        g_string_append (str, "'{\n");
        for (i = 0; i < _entry_count; i++) {
            g_autofree gchar *struct_str = NULL;

            g_string_append_printf (str, "%s    [%u] = {\n", line_prefix, i);
            struct_str = _mbim_message_print_mbim_phonebook_entry_struct (tmp[i], new_line_prefix);
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
/* Message (Set): MBIM Message Phonebook Delete */

MbimMessage *
mbim_message_phonebook_delete_set_new (
    MbimPhonebookFlag filter_flag,
    guint32 filter_message_index,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_PHONEBOOK,
                                                 MBIM_CID_PHONEBOOK_DELETE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, filter_flag);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, filter_message_index);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_phonebook_delete_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  FilterFlag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PHONEBOOK_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_phonebook_flag_get_string ((MbimPhonebookFlag)tmp));
#elif defined __MBIM_PHONEBOOK_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_phonebook_flag_build_string_from_mask ((MbimPhonebookFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  FilterMessageIndex = ", line_prefix);
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
/* Message (Response): MBIM Message Phonebook Delete */

gboolean
mbim_message_phonebook_delete_response_parse (
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
mbim_message_phonebook_delete_response_get_printable (
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
/* Message (Set): MBIM Message Phonebook Write */

MbimMessage *
mbim_message_phonebook_write_set_new (
    MbimPhonebookWriteFlag save_flag,
    guint32 save_index,
    const gchar *number,
    const gchar *name,
    GError **error)
{
    MbimMessageCommandBuilder *builder;

    builder = _mbim_message_command_builder_new (0,
                                                 MBIM_SERVICE_PHONEBOOK,
                                                 MBIM_CID_PHONEBOOK_WRITE,
                                                 MBIM_MESSAGE_COMMAND_TYPE_SET);
    {
        _mbim_message_command_builder_append_guint32 (builder, save_flag);
    }
    {
        _mbim_message_command_builder_append_guint32 (builder, save_index);
    }
    {
        _mbim_message_command_builder_append_string (builder, number);
    }
    {
        _mbim_message_command_builder_append_string (builder, name);
    }

    return _mbim_message_command_builder_complete (builder);
}

static gchar *
mbim_message_phonebook_write_set_get_printable (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error)
{
    GString *str;
    GError *inner_error = NULL;
    guint32 offset = 0;

    str = g_string_new ("");

    g_string_append_printf (str, "%s  SaveFlag = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
#if defined __MBIM_PHONEBOOK_WRITE_FLAG_IS_ENUM__
        g_string_append_printf (str, "'%s'", mbim_phonebook_write_flag_get_string ((MbimPhonebookWriteFlag)tmp));
#elif defined __MBIM_PHONEBOOK_WRITE_FLAG_IS_FLAGS__
        {
            g_autofree gchar *tmpstr = NULL;

            tmpstr = mbim_phonebook_write_flag_build_string_from_mask ((MbimPhonebookWriteFlag)tmp);
            g_string_append_printf (str, "'%s'", tmpstr);
        }
#else
# error neither enum nor flags
#endif

    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  SaveIndex = ", line_prefix);
    {
        guint32 tmp;

        if (!_mbim_message_read_guint32 (message, offset, &tmp, &inner_error))
            goto out;
        offset += 4;
        g_string_append_printf (str, "'%" G_GUINT32_FORMAT "'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Number = ", line_prefix);
    {
        g_autofree gchar *tmp = NULL;

        if (!_mbim_message_read_string (message, 0, offset, &tmp, &inner_error))
            goto out;
        offset += 8;
        g_string_append_printf (str, "'%s'", tmp);
    }
    g_string_append (str, "\n");

    g_string_append_printf (str, "%s  Name = ", line_prefix);
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
/* Message (Response): MBIM Message Phonebook Write */

gboolean
mbim_message_phonebook_write_response_parse (
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
mbim_message_phonebook_write_response_get_printable (
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
    [MBIM_CID_PHONEBOOK_CONFIGURATION] = {
        .query_cb = mbim_message_phonebook_configuration_query_get_printable,
        .response_cb = mbim_message_phonebook_configuration_response_get_printable,
        .notification_cb = mbim_message_phonebook_configuration_notification_get_printable,
    },
    [MBIM_CID_PHONEBOOK_READ] = {
        .query_cb = mbim_message_phonebook_read_query_get_printable,
        .response_cb = mbim_message_phonebook_read_response_get_printable,
    },
    [MBIM_CID_PHONEBOOK_DELETE] = {
        .set_cb = mbim_message_phonebook_delete_set_get_printable,
        .response_cb = mbim_message_phonebook_delete_response_get_printable,
    },
    [MBIM_CID_PHONEBOOK_WRITE] = {
        .set_cb = mbim_message_phonebook_write_set_get_printable,
        .response_cb = mbim_message_phonebook_write_response_get_printable,
    },
};

gchar *
__mbim_message_phonebook_get_printable_fields (
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
